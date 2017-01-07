/*
 * schedulingEval.cpp
 *
 *  Created on: 7 de jun de 2016
 *      Author: Adriano
 */

#include "schedulingEval.h"

bool pairCompare(const std::pair<unsigned, double>& _p1,
		const std::pair<unsigned, double>& _p2) {
	return _p1.second < _p2.second;
}

SchedulingEval::SchedulingEval(unsigned int _M, unsigned int _N,
		const std::vector<std::vector<unsigned int> >& _p,
		const std::vector<unsigned int>& _d) :
		M(_M), N(_N), p(_p), d(_d) {
}

void SchedulingEval::operator ()(Scheduling & _scheduling) {
//	double mspan = makespan(_scheduling);
//	_scheduling.fitness(mspan);

	std::cout
			<< "--------------------------------------------------------------------------------"
			<< std::endl;

	std::vector<unsigned> schedulingDecoded = decode(_scheduling);

	unsigned penalizador = process(schedulingDecoded);

	double sum = 0;
	for (unsigned i = 0; i < _scheduling.size(); i++)
		sum += _scheduling[i] * _scheduling[i];

	_scheduling.fitness(0 - (penalizador * penalizador));     // maximizing only
}

double SchedulingEval::makespan(const Scheduling & _scheduling) {
	// completion times computation for each job on each machine
	// C[i][j] = completion of the jth job of the scheduling on the ith machine
	std::vector<std::vector<unsigned int> > C = completionTime(_scheduling);

	return C[M - 1][_scheduling[N - 1]];
}

double SchedulingEval::tardiness(const Scheduling & _scheduling) {
	// completion times computation for each job on each machine
	// C[i][j] = completion of the jth job of the scheduling on the ith machine
	std::vector<std::vector<unsigned int> > C = completionTime(_scheduling);

	// tardiness computation
	unsigned int long sum = 0;
	for (unsigned int j = 0; j < N; j++)
		sum += (unsigned int) std::max(0,
				(int) (C[M - 1][_scheduling[j]] - d[_scheduling[j]]));

	return sum;
}

SchedulingEval::SchedulingEval() {
	M = 0;
	N = 0;
	o = Railway::getOperations();
}

std::vector<std::vector<unsigned int> > SchedulingEval::completionTime(
		const Scheduling & _scheduling) {

	//std::vector<std::vector<unsigned int> > C(M, N);
	std::vector<std::vector<unsigned int> > C;

	C[0][_scheduling[0]] = p[0][_scheduling[0]];

	for (unsigned int j = 1; j < N; j++)
		C[0][_scheduling[j]] = C[0][_scheduling[j - 1]] + p[0][_scheduling[j]];

	for (unsigned int i = 1; i < M; i++)
		C[i][_scheduling[0]] = C[i - 1][_scheduling[0]] + p[i][_scheduling[0]];

	for (unsigned int i = 1; i < M; i++)
		for (unsigned int j = 1; j < N; j++)
			C[i][_scheduling[j]] = std::max(C[i][_scheduling[j - 1]],
					C[i - 1][_scheduling[j]]) + p[i][_scheduling[j]];
	return C;
}

unsigned SchedulingEval::process(std::vector<unsigned> & _schedulingDecoded) {
	unsigned res = 1;

	try {
		/** Para cada segmento ira guardar os trens que estao ocupando as linhas. */
		std::map<unsigned, std::vector<unsigned> > mapSectionOccupation;
		/** Para cada segmento vai guardar a ultima data de chegada e a ultima data de saida. */
		std::map<unsigned, std::pair<unsigned, unsigned> > mapSectionTimes;
		/** Guarda as rotas dos trens. */
		std::map<unsigned, std::vector<unsigned> > mapTrainRoutes;
		/** Serve para mover os trens para os proximos segmento da rota */
		std::map<unsigned, unsigned> mapTrainRouteIdx;
		/** Guarda ultima operacao do trem */
		std::map<unsigned, std::pair<unsigned, unsigned> > mapTrainSectionArrival;
		/** Vetor com operacoes que nao puderam ser processadas */
		std::vector<std::pair<unsigned, unsigned> > vectOpRest;
		/** referencia da linha do tempo */
		unsigned timeRef = 0;

		std::vector<unsigned> vectDeadlocks;

		std::vector<unsigned> schedulingFinal;

		mapTrainRoutes = Railway::getTrainRoutes();

		unsigned count = 0;

		std::multimap<unsigned, unsigned> mmapSectionOccupation;

		/** movimentos tabu */
		std::map<unsigned, std::vector<unsigned> > tabu;

		mapSectionQtdOccupations.clear();
		mapSectionReleaseTime.clear();
		/** inicializa a quantidade de ocupacoes em cada secao */
		for (unsigned i = 1; i <= Railway::numSections(); i++) {
			mapSectionQtdOccupations[i] = 0;
			mapSectionReleaseTime[i] = 0;

		}

//	/** Initialize mapSectionOccupation */
//	for (unsigned i = 1; i <= Railway::numSections(); i++) {
//		std::vector<unsigned> v(Railway::getSectionCapacity(i));
//		std::vector<unsigned> t(2);
//
//		/** vector with size equals section capacity */
//		for (unsigned j = 0; j < v.size(); j++)
//			v.push_back(-1);
//		mapSectionOccupation[i] = v;
//
//		/** vector with occupation time and release time off section */
//		for (unsigned j = 0; j < t.size(); j++)
//			t.push_back(0);
//		mapSectionTimes[i] = t;
//
//	}

//	std::cout << "Process" << std::endl;

		/** inicializa o vetor com o indice das operacoes dos trens */
		for (std::map<unsigned, std::vector<unsigned> >::iterator it =
				mapTrainRoutes.begin(); it != mapTrainRoutes.end(); ++it) {
			mapTrainRouteIdx[it->first] = -1;
		}

		unsigned mspan = 0;

		std::cout << "operations => " << std::endl;

		//auto oIt = _schedulingDecoded.begin();

		//while (oIt != _schedulingDecoded.end()) {
		for (unsigned i = 0; i < _schedulingDecoded.size(); i++) {
			/** trem */
			unsigned train = _schedulingDecoded[i];
			/** direcao do trem */
			signed direction = Railway::getTrainDirection(train);
			/** indice da operacao do trem */
			unsigned operation = ++mapTrainRouteIdx[train];
			/** secao para qual o trem devera ir */
			unsigned section = mapTrainRoutes[train][operation];
			/** headway(tempo de percurso) da secao */
			unsigned headway = Railway::getSectionHeadway(section);

			unsigned nextSection = section + direction;
			unsigned prevSection = section - direction;

			std::cout << "[" << train << ", " << section << ", " << headway
					<< "]" << " Train=" << train << "; Direction=" << direction
					<< "; Operation=" << operation << "; prevSection="
					<< prevSection << "; Section=" << section
					<< "; nextSection=" << nextSection;

//			/** verifica os deadlocks */
//			if (vectDeadlocks.size() > 0) {
//				unsigned retry = 0;
//
//				bool deadlockCanMove = false;
//
//				while (vectDeadlocks.size() > 0) {
//					if (retry > vectDeadlocks.size())
//						break;
//
//					unsigned deadlockTrain = vectDeadlocks[0];
//					unsigned deadlockDirection = Railway::getTrainDirection(
//							deadlockTrain);
//					unsigned deadlockOperation =
//							++mapTrainRouteIdx[deadlockTrain];
//					unsigned deadlockSection =
//							mapTrainRoutes[deadlockTrain][deadlockOperation];
//					unsigned deadlockHeadway = Railway::getSectionHeadway(
//							deadlockSection);
//
//					deadlockCanMove = verifyMovement(deadlockTrain,
//							deadlockDirection, deadlockSection);
//
//					if (deadlockCanMove) {
//						vectDeadlocks.erase(vectDeadlocks.begin());
//
//						mapSectionQtdOccupations[deadlockSection] += 1;
//						mapSectionReleaseTime[deadlockSection] +=
//								deadlockHeadway;
//
//						if (operation > 1) {
//							mapSectionQtdOccupations[deadlockSection
//									+ deadlockDirection] -= 1;
//						}
//
//						schedulingFinal.push_back(deadlockTrain);
//					}
//
//					retry++;
//				}
//			}

			bool canMove = verifyMovement(train, direction, section);

			if (canMove) {
				std::cout << " movement valid!!!" << std::endl;

				/** insere o trem no mapeamento de ocupacoes */
				mmapSectionOccupation.insert(std::make_pair(section, train));

				/** retira o trem do mapeamento da secao anterior */
				if (mmapSectionOccupation.count(prevSection) > 0) {
					std::pair<std::multimap<unsigned, unsigned>::iterator,
							std::multimap<unsigned, unsigned>::iterator> iterRange =
							mmapSectionOccupation.equal_range(prevSection);

					for (std::multimap<unsigned, unsigned>::iterator it =
							iterRange.first; it != iterRange.second; ++it) {
						if (it->second == train) {
							mmapSectionOccupation.erase(it);
							break;
						}
					}
				}

				if (tabu.count(train) > 0)
					tabu.erase(train);

				if (operation < mapTrainRoutes[train].size() - 1) {
					mapSectionQtdOccupations[section] += 1;
					mapSectionReleaseTime[section] += headway;
				} else {
					std::cout << "train " << train << " arrival in destiny"
							<< std::endl;
				}

				if (operation > 0) {
					//std::cout << "train=" << train << "; direction=" << direction << "; operation=" << operation << std::endl;
					//std::cout << "QtdOccupation before = " << mapSectionQtdOccupations[prevSection] << std::endl;
					mapSectionQtdOccupations[prevSection] -= 1;
					//std::cout << "QtdOccupation after = " << mapSectionQtdOccupations[prevSection] << std::endl;
				}

				schedulingFinal.push_back(train);

				mspan += headway;
				//oIt++;
			} else {
				std::cout << " movement invalid!!!" << std::endl;

				unsigned tempSection = section;

				if (mmapSectionOccupation.count(tempSection) == 0)
					tempSection += direction;

				if (mmapSectionOccupation.count(tempSection) > 0) {
					std::multimap<unsigned, unsigned>::iterator it =
							mmapSectionOccupation.find(tempSection);
					unsigned aTrain = it->second;

					tabu[train].push_back(aTrain);
					unsigned temp = train;

					unsigned j = i;
					for (unsigned idx = i; idx < _schedulingDecoded.size();
							idx++) {
						if (_schedulingDecoded[idx] == aTrain) {
							j = idx;
							break;
						}
					}

					std::cout << "swap " << train << " with " << aTrain
							<< " in position " << j << std::endl;

					_schedulingDecoded[i] = aTrain;
					_schedulingDecoded[j] = temp;

					i--;
					count++;
				}

//				/** troca com o proximo trem diferente */
//				for (unsigned j = i; j < _schedulingDecoded.size(); j++) {
//					unsigned anotherTrain = _schedulingDecoded[j];
//
//					if (train != anotherTrain) {
//						std::cout << "swap " << train << " with "
//								<< anotherTrain << std::endl;
//						if ((tabu[train].size() > 1
//								&& std::find(tabu[train].begin(),
//										tabu[train].end(), anotherTrain)
//										!= tabu[train].end())) {
//							std::cout << "movement tabu" << std::endl;
//							continue;
//						}
//
//						tabu[train].push_back(anotherTrain);
//						unsigned temp = train;
//						_schedulingDecoded[i] = anotherTrain;
//						_schedulingDecoded[j] = temp;
//						i--;
//						count++;
//
//						break;
//					}
//				}
//
				if (count > 20) {
					std::cout << "@@@@@ exiting by count > 20!!!" << std::endl;
					break;
				}
//
//				//std::iter_swap(oIt, _schedulingDecoded.end()-1);
//
//				//oIt--;

				mapTrainRouteIdx[train]--;

				vectDeadlocks.push_back(train);
				res = 9999;
			}

//			/** se o segmento nao tem nenhuma ocupacao ou se tem linha livre */
//			if (mapSectionOccupation.count(section) == 0
//					|| Railway::getSectionCapacity(section)
//							- mapSectionOccupation[section].size()) {
//				/** ultima chegada no segmento */
//				unsigned lastArrival = 0;
//				/** ultima partida no segmento */
//				unsigned lastDeparture = 0;
//
//				if (mapSectionTimes.count(section) == 0) {
//					mapSectionTimes[section].first = timeRef;
//					mapSectionTimes[section].second = timeRef + headway;
//				} else {
//
//				}
//
//				/** insere o trem no mapeamento de section e occupation */
//				mapSectionOccupation[section].push_back(train);
//			} else {
//				/** insere o par train/section no pool de operacoes */
//				vectOpRest.push_back(std::make_pair(train, section));
//			}
//
		}

//		if (vectDeadlocks.size() > 0) {
//			auto itd = vectDeadlocks.begin();
//
//			std::cout << std::endl << "qtd de operacoes em deadlock : "
//					<< vectDeadlocks.size() << std::endl;
//			std::cout << "vetor de operacoes em deadlock : " << std::endl;
//			while (itd != vectDeadlocks.end()) {
//				std::cout << *itd << " ";
//				itd++;
//			}
//		}

		std::cout << "makespan = " << mspan << std::endl;

		std::cout << "final => " << schedulingFinal.size();

		for (std::vector<unsigned>::iterator iter = schedulingFinal.begin();
				iter != schedulingFinal.end(); ++iter)
			std::cout << " " << *iter;

		std::cout << std::endl;

//	// como verificar se map contains key
//	std::map<unsigned, std::vector<unsigned> >::iterator it =
//			mapSectionOccupation.find(1);
//	if (it != mapSectionOccupation.end())
//		std::cout << "encontrou a key 1 no map." << std::endl;

		//std::cout << std::endl;
	} catch (std::exception& e) {
		std::cout << "Exception = " << e.what() << std::endl;
	}

	return res;
}

bool SchedulingEval::verifyMovement(unsigned _train, signed _direction,
		unsigned _section) {
	/** capacidade da secao */
	unsigned capacity = Railway::getSectionCapacity(_section);
	/** quantidade de ocupacoes na secao */
	unsigned occupations = mapSectionQtdOccupations[_section];

	unsigned nextCapacity;
	unsigned nextOccupations;

	bool canMove = false;

	/** se nao houver capacidade para receber movimento do trem */
	if (capacity == occupations) {
		canMove = false;
	} else if ((_direction == 1 && _section == Railway::numSections())
			|| (_direction == -1 && _section == 1)) {
		canMove = true;
	} else if (capacity == 1) {
		if ((_direction == 1 && _section - Railway::numSections() > 1)
				|| (_direction == -1 && _section > 1)) {
			nextCapacity = Railway::getSectionCapacity(_section + _direction);
			nextOccupations = mapSectionQtdOccupations[_section + _direction];

			if (nextOccupations < nextCapacity) {
				if ((nextCapacity - nextOccupations) > 1) {
					canMove = true;
				} else {
					if ((_direction == 1
							&& _section - Railway::numSections() > 2)
							|| (_direction == -1 && _section > 2)) {
						nextCapacity = Railway::getSectionCapacity(
								_section + (2 * _direction));
						nextOccupations = mapSectionQtdOccupations[_section
								+ (2 * _direction)];

						if ((nextCapacity - nextOccupations) >= 1)
							canMove = true;
					}
				}
			}
		}
	} else {
		if ((capacity - occupations) > 1) {
			canMove = true;
		} else {
			if ((_direction == 1 && _section - Railway::numSections() > 1)
					|| (_direction == -1 && _section > 1)) {
				nextCapacity = Railway::getSectionCapacity(
						_section + _direction);
				nextOccupations =
						mapSectionQtdOccupations[_section + _direction];

				if ((nextCapacity - nextOccupations) >= 1)
					canMove = true;
			}
		}
	}

	return canMove;
}
//std::vector<unsigned> SchedulingEval::decode(const Scheduling& _scheduling) {
//	std::vector<unsigned> vectOperations;
//	std::vector<std::pair<unsigned, double> > vectAux;
//
//	unsigned len = _scheduling.size();
//
//	std::cout << "\tencoded => ";
//	for (unsigned i = 0; i < len; i++) {
//		vectAux.push_back(std::make_pair(i, _scheduling[i]));
//		std::cout << _scheduling[i] << " ";
//	}
//
//	std::sort(vectAux.begin(), vectAux.end(), pairCompare);
//
//	std::cout << std::endl << "\tdecoded :: ";
//	for (unsigned i = 0; i < len; i++) {
//		vectOperations.push_back(vectAux[i].first);
//		std::cout << o[vectAux[i].first] << " ";
//	}
//
//	std::cout << std::endl;
//
//	return vectOperations;
//}

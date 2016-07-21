/*
 * schedulingInit.cpp
 *
 *  Created on: 7 de jun de 2016
 *      Author: Adriano
 */

#include "schedulingInit.h"

//bool pairCompare(const std::pair<unsigned, double> & _p1,
//		const std::pair<unsigned, double> & _p2) {
//	return _p1.second < _p2.second;
//}

void SchedulingInit::operator ()(Scheduling & _scheduling) {

	//std::cout << "init" << std::endl;
	std::vector<std::pair<unsigned, double> > vectAux;
	unsigned maxLen = 0;
	double randomValue;

	_scheduling.clear();

//	for (unsigned i = 0; i < Railway::numTrains(); i++) {
//		for (unsigned j = 0; j < Railway::getNumStepsByTrain(i + 1); j++) {
//			randomValue = (unsigned) (rand() % Railway::getNumOperations() + 1);
//			vectAux.push_back(std::make_pair(i + 1, randomValue));
//		}
//	}

	maxLen = Railway::getNumOperations();

	// gera semente randomica.
	// srand(time(0));

	for (unsigned i = 0; i < maxLen; i++) {
		randomValue = (double) (rand() % maxLen) / maxLen;

		//std::cout << randomValue << " ";

		vectAux.push_back(std::make_pair(i, randomValue));
	}

	for (std::pair<unsigned, double> p : vectAux) {
		_scheduling.push_back(p.second);
		//std::cout << p.first << " " << p.second << " ";
		//std::cout << p.second << " ";
	}

//	std::sort(vectAux.begin(), vectAux.end(), pairCompare);
//
//	std::cout << "sorting ";
//	for (std::pair<unsigned, double> p : vectAux) {
//		std::cout << "[" << p.first << ", " << p.second << "] ";
//	}
//	std::cout << std::endl;

	//std::cout << std::endl;

}

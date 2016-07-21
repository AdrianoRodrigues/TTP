/*
 * railway.cpp
 *
 *  Created on: 8 de jun de 2016
 *      Author: Adriano
 */

#include "railway.h"

static std::map<unsigned, std::pair<unsigned, unsigned> > mapSections; // Secoes e suas capacidades.
static std::map<unsigned, std::vector<unsigned> > mapTrainRoute; // Trens e suas respectivas rotas.
static std::map<unsigned, std::pair<unsigned, unsigned> > mapTrainLocation;
static std::map<unsigned, signed> mapTrainDirection;
static std::vector<unsigned> vectOperations;

struct TTrain {
	unsigned ID;
	unsigned direction;
	unsigned origin;
	unsigned destiny;
	unsigned lastSection;
	std::vector<unsigned> route;
};

struct TSection {
	unsigned ID;
	unsigned capacity;
	std::vector<unsigned> occup(capacity);
};

int myrandom (int i) {
	return rng.random(i);
}

/**
 * @brief Loading instance of problem
 */
void Railway::load(const char* _fileName) {
	std::ifstream file(_fileName);
	std::cout << ">> Loading file " << _fileName << " ..." << std::endl;

	if (file) {
		unsigned numSections;
		unsigned numTrains;
		unsigned numPlans;

		unsigned track;
		unsigned origin;
		unsigned destiny;
		unsigned section;
		unsigned train;

		std::string line;

		std::getline(file, line);
		std::stringstream lineSS(line);

		// le a quantidade de secoes.
		lineSS >> numSections;

		std::cout << "numSections = " << numSections << std::endl;

		for (unsigned i = 0; i < numSections; i++) {
			std::getline(file, line);
			lineSS.str(""); // limpa o buffer.
			lineSS << line;

			// mapSections[section].first => capacidade de cada secao.
			// mapSections[section].second => headway de cada secao.
			lineSS >> section;
			lineSS >> mapSections[section].first >> mapSections[section].second;

			std::cout << "Section = " << section << "; Capacity = "
					<< mapSections[section].first << "; Headway = "
					<< mapSections[section].second << std::endl;
		}

		std::getline(file, line);
		lineSS.str(""); // limpa o buffer.
		lineSS << line;

		// le a quantidade de trens circulando.
		lineSS >> numTrains;

		std::cout << "numTrains = " << numTrains << std::endl;

		signed direction;

		for (unsigned i = 0; i < numTrains; i++) {
			std::getline(file, line);
			lineSS.clear(); // limpa o buffer.
			lineSS << line;

			direction = 1;

			// le a linha atual, a secao origem e a secao destino do trem.
			lineSS >> train >> track >> origin >> destiny;

			if (destiny < origin)
							direction = -1;

			std::cout << "Train = " << train << "; Direction = " << direction << "; Track = " << track
					<< "; Origin = " << origin << "; Destiny = " << destiny
					<< std::endl;

			mapTrainDirection[train] = direction;

			// le o percurso do trem.
			std::stringstream route;
			while (lineSS >> section) {
				mapTrainRoute[train].push_back(section);

				if (!route.str().empty())
					route << " -> ";

				route << section;
			}

			std::cout << "Route of Train " << train << " => " << route.str()
					<< std::endl;
		}

		for (unsigned i = 0; i < Railway::numTrains(); i++)
			for (unsigned j = 0; j < Railway::getNumStepsByTrain(i + 1); j++)
				vectOperations.push_back(i + 1);

//		unsigned t = rng.random(vectOperations.size());
//
//		for (int i = 0; i < t; i++) {
//			std::swap(vectOperations[rng.random(vectOperations.size())],
//					vectOperations[rng.random(vectOperations.size())]);
//		}

		// embaralha o vetor
		std::random_shuffle(vectOperations.begin(), vectOperations.end(), myrandom);

		std::cout << "Vetor de operacoes: " << std::endl;
		for (unsigned i : vectOperations)
			std::cout << i << " ";
		std::cout << std::endl;

		file.close();
	} else {
		std::cout << _fileName << " doesn't exist !!!" << std::endl;
	}
}

unsigned Railway::numTrains() {
	return mapTrainRoute.size();
}

unsigned Railway::numSections() {
	return mapSections.size();
}

unsigned Railway::getNumStepsByTrain(unsigned _train) {
	return mapTrainRoute[_train].size(); // nao conta a origem.
}

unsigned Railway::getNumOperations() {
	unsigned count = 0;

	for (std::map<unsigned, std::vector<unsigned> >::iterator it =
			mapTrainRoute.begin(); it != mapTrainRoute.end(); ++it) {
		count += it->second.size();
	}

	return count;
}

std::map<unsigned, std::vector<unsigned> > Railway::getTrainRoutes() {
	return mapTrainRoute;
}

std::vector<unsigned> Railway::getOperations() {
	return vectOperations;
}

unsigned Railway::getSectionHeadway(unsigned _section) {
	return mapSections[_section].second;
}

unsigned Railway::getSectionCapacity(unsigned _section) {
	return mapSections[_section].first;
}

signed Railway::getTrainDirection(unsigned _train) {
	return mapTrainDirection[_train];
}

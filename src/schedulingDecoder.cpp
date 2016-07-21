/*
 * schedulingDecoder.cpp
 *
 *  Created on: 26 de jun de 2016
 *      Author: adriano
 */

#include "schedulingDecoder.h"

bool compare(const std::pair<unsigned, double>& _p1,
		const std::pair<unsigned, double>& _p2) {
	return _p1.second < _p2.second;
}

std::vector<unsigned> decode(const Scheduling& _scheduling) {
	std::vector<unsigned> vectOperations;
	std::vector<unsigned> operations;
	std::vector<std::pair<unsigned, double> > vectAux;

	operations = Railway::getOperations();

	unsigned len = _scheduling.size();

	std::cout << "encoded => " << _scheduling.size();
	for (unsigned i = 0; i < len; i++) {
		vectAux.push_back(std::make_pair(i, _scheduling[i]));
		std::cout << " " << _scheduling[i];
	}

	std::sort(vectAux.begin(), vectAux.end(), compare);

	std::cout << std::endl << "decoded => " << _scheduling.size();
	for (unsigned i = 0; i < len; i++) {
		vectOperations.push_back(operations[vectAux[i].first]);
		std::cout << " " << operations[vectAux[i].first];
	}

	std::cout << std::endl;

	return vectOperations;
}

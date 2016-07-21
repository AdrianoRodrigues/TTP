/*
 * railway.h
 *
 *  Created on: 8 de jun de 2016
 *      Author: Adriano
 */

#ifndef SRC_RAILWAY_H_
#define SRC_RAILWAY_H_

#include <iostream>
#include <fstream>
#include <sstream>
#include <utility>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

#include <utils/eoRNG.h>

namespace Railway {
void load(const char * _fileName);
unsigned numTrains();
unsigned numSections();
unsigned getNumStepsByTrain(unsigned);
unsigned getNumOperations();
unsigned getSectionHeadway(unsigned);
unsigned getSectionCapacity(unsigned);
std::map<unsigned, std::vector<unsigned> > getTrainRoutes();
std::vector<unsigned> getOperations();
signed getTrainDirection(unsigned _train);

}
;

#endif /* SRC_RAILWAY_H_ */

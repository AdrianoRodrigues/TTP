/*
 * schedulingSwap.cpp
 *
 *  Created on: 7 de jun de 2016
 *      Author: Adriano
 */

#include "schedulingSwap.h"

bool SchedulingSwap::operator ()(Scheduling& _scheduling) {

	std::swap(_scheduling[rng.random(_scheduling.size())],
			_scheduling[rng.random(_scheduling.size())]);

	_scheduling.invalidate();

	return true;

}

/*
 * schedulingXover.cpp
 *
 *  Created on: 26 de jun de 2016
 *      Author: adriano
 */

#include "schedulingXover.h"

bool SchedulingXover::operator ()(Scheduling& _scheduling1,
		Scheduling& _scheduling2) {

	unsigned cut1 = rng.random(_scheduling1.size()), cut2 = rng.random(
			_scheduling2.size());

	if (cut2 < cut1)
		std::swap(cut1, cut2);

	// Between the cuts
	for (unsigned i = cut1; i < cut2; i++)
		std::swap(_scheduling1[i], _scheduling2[i]);

	_scheduling1.invalidate();
	_scheduling2.invalidate();

	return true;

}

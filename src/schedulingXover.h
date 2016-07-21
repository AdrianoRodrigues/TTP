/*
 * schedulingXover.h
 *
 *  Created on: 26 de jun de 2016
 *      Author: adriano
 */

#ifndef SRC_SCHEDULINGXOVER_H_
#define SRC_SCHEDULINGXOVER_H_

#include <eoOp.h>
#include <utils/eoRNG.h>
#include "scheduling.h"

class SchedulingXover : public eoQuadOp<Scheduling> {

public:

	bool operator () (Scheduling & _scheduling1, Scheduling & _scheduling2) ;

};

#endif /* SRC_SCHEDULINGXOVER_H_ */

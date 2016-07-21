/*
 * schedulingSwap.h
 *
 *  Created on: 7 de jun de 2016
 *      Author: Adriano
 */

#ifndef SRC_SCHEDULINGSWAP_H_
#define SRC_SCHEDULINGSWAP_H_

#include <eoOp.h>
#include "scheduling.h"

class SchedulingSwap : public eoMonOp<Scheduling> {

public:

	bool operator () (Scheduling & _scheduling) ;

};

#endif /* SRC_SCHEDULINGSWAP_H_ */

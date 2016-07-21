/*
 * schedulingInit.h
 *
 *  Created on: 7 de jun de 2016
 *      Author: Adriano
 */

#ifndef SRC_SCHEDULINGINIT_H_
#define SRC_SCHEDULINGINIT_H_

#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <eoInit.h>

#include "railway.h"
#include "scheduling.h"

class SchedulingInit: public eoInit<Scheduling> {

public:

	void operator ()(Scheduling & _scheduling);

private:



};

#endif /* SRC_SCHEDULINGINIT_H_ */

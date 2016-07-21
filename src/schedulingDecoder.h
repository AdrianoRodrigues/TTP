/*
 * schedulingDecoder.h
 *
 *  Created on: 26 de jun de 2016
 *      Author: adriano
 */

#ifndef SRC_SCHEDULINGDECODER_H_
#define SRC_SCHEDULINGDECODER_H_

#include <algorithm>

#include "railway.h"
#include "scheduling.h"

std::vector<unsigned> decode(const Scheduling & _scheduling);

#endif /* SRC_SCHEDULINGDECODER_H_ */

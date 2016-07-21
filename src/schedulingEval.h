/*
 * schedulingEval.h
 *
 *  Created on: 7 de jun de 2016
 *      Author: Adriano
 */

#ifndef SRC_SCHEDULINGEVAL_H_
#define SRC_SCHEDULINGEVAL_H_

#include <stdlib.h>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <exception>

#include <eoEvalFunc.h>

#include "railway.h"
#include "scheduling.h"
#include "schedulingDecoder.h"

class SchedulingEval: public eoEvalFunc<Scheduling> {

public:

	SchedulingEval();

	/**
	 * Ctor
	 * @param _M the number of machines
	 * @param _N the number of jobs to schedule
	 * @param _p the processing times
	 * @param _d the due dates
	 */
	SchedulingEval(unsigned int _M, unsigned int _N,
			const std::vector<std::vector<unsigned int> > & _p,
			const std::vector<unsigned int> & _d);

	void operator ()(Scheduling & _scheduling);

	//std::vector<unsigned> decode(const Scheduling & _scheduling);

private:

	/** number of machines */
	unsigned int M;
	/** number of jobs */
	unsigned int N;
	/** p[i][j] = processing time of job j on machine i */
	std::vector<std::vector<unsigned int> > p;
	/** d[j] = due-date of the job j */
	std::vector<unsigned int> d;
	/** all operations */
	std::vector<unsigned int> o;

	/** mapeia a secao com a quantidade de ocupacoes presentes */
	std::map<unsigned, unsigned> mapSectionQtdOccupations;
	std::map<unsigned, unsigned> mapSectionReleaseTime;

	/**
	 * computation of the makespan
	 * @param _scheduling the genotype to evaluate
	 */
	double makespan(const Scheduling & _scheduling);

	/**
	 * computation of the tardiness
	 * @param _scheduling the genotype to evaluate
	 */
	double tardiness(const Scheduling & _scheduling);

	/**
	 * computation of the completion times of a scheduling (for each job on each machine)
	 * C[i][j] = completion of the jth job of the scheduling on the ith machine
	 * @param _scheduling the genotype to evaluate
	 */
	std::vector<std::vector<unsigned int> > completionTime(
			const Scheduling & _scheduling);

	unsigned process(std::vector<unsigned> & _schedulingDecoded);

	bool verifyMovement(unsigned _train, signed _direction, unsigned _section);

};

#endif /* SRC_SCHEDULINGEVAL_H_ */

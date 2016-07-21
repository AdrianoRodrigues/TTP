/*
 * ttp.cpp
 *
 *  Created on: 7 de jun de 2016
 *      Author: Adriano
 */

#include <iostream>
#include <utility>

#include <eoEasyEA.h>
#include <eoSGA.h>
#include <eoGenContinue.h>
#include <eoStochTournamentSelect.h>
#include <eoSGATransform.h>

#include "railway.h"
#include "scheduling.h"
#include "schedulingDecoder.h"
#include "schedulingEval.h"
#include "schedulingInit.h"
#include "schedulingXover.h"
#include "schedulingSwap.h"
#include <exception>

int main(int argc, char *argv[]) {

	const double T_SIZE = 0.7;           // StochTournament rate
	const unsigned int POP_SIZE = 5;     // tamanho da populacao
	const unsigned int ITERATIONS = 5; // quantidade de iteracoes
	const float CROSS_RATE = 0.8;        // taxa de crossover
	const float MUT_RATE = 0.9;          // taxa de mutacao

	if (argc != 2) {
		std::cerr << std::endl << "Usage : ./ttp [instance]" << std::endl
				<< std::endl;
		return 1;
	}

	try {
		Railway::load(argv[1]);

		SchedulingInit init; // init a random solution.

		SchedulingEval eval; // evaluator.

		// inicia a populacao com [POP_SIZE] individuos.
		eoPop<Scheduling> pop(POP_SIZE, init); // population.

		/** avalia toda a populacao */
		apply<Scheduling>(eval, pop);

		// imprime o melhor individuo.
		std::cout << "From => " << pop.best_element() << std::endl;

		std::cout << "From => ";
		decode(pop.best_element());

		// imprime toda a populacao.
		//pop.sortedPrintOn(std::cout);

		// criterio de parada, 500 iteracoes.
		eoGenContinue<Scheduling> continuator(ITERATIONS); /* Continuator (A fixed number of
		 500 iterations */

		eoStochTournamentSelect<Scheduling> select(T_SIZE);

		SchedulingXover xover;

		SchedulingSwap mutation;

		//StardardGA = SGA
		eoSGA<Scheduling> ga(select, xover, CROSS_RATE, mutation, MUT_RATE,
				eval, continuator);
		ga(pop); //APLICA O SGA!

		std::cout << "To => " << pop.best_element() << std::endl;

		std::cout << "To => ";
		decode(pop.best_element());

		pop.sort();

		std::cout << pop[0].fitness() << std::endl;

		std::cout << std::endl << "@@@@@ Done!" << std::endl;

	} catch (std::exception& e) {
		std::cout << "main exception => " << e.what() << std::endl;
	}

}


#include "GaussianGroupingEvaluatorFactory.h"
#include "GeneticAlgorithm.h"
#include "GroupingEvaluator.h"
#include "Optimizer.h"
#include "SimulationParams.h"

using namespace NGroupingChallenge;

int main()
{
	CGaussianGroupingEvaluatorFactory c_evaluator_factory(NUMBER_OF_GROUPS, NUMBER_OF_POINTS, NUMBER_OF_MULTIVARIATE_GAUSSIAN_DISTRIBUTION);

	c_evaluator_factory
		.cAddDimension(MEAN_MIN, MEAN_MAX, 1.0, 1.0)
		.cAddDimension(MEAN_MIN, MEAN_MAX, 1.0, 1.0)
		.cAddDimension(MEAN_MIN, MEAN_MAX, 1.0, 1.0)
		.cAddDimension(MEAN_MIN, MEAN_MAX, 1.0, 1.0)
		.cAddDimension(MEAN_MIN, MEAN_MAX, 1.0, 1.0)
		.cAddDimension(MEAN_MIN, MEAN_MAX, 1.0, 1.0)
		.cAddDimension(MEAN_MIN, MEAN_MAX, 1.0, 1.0)
		.cAddDimension(MEAN_MIN, MEAN_MAX, 1.0, 1.0)
		.cAddDimension(MEAN_MIN, MEAN_MAX, 1.0, 1.0)
		.cAddDimension(MEAN_MIN, MEAN_MAX, 1.0, 1.0);

	CGroupingEvaluator* pc_evaluator = c_evaluator_factory.pcCreateEvaluator(0);

	GeneticAlgorithm ga(POPULATION_SIZE,CROSSING_CHANCE,MUTATION_CHANCE,*pc_evaluator);

	COptimizer c_optimizer(*pc_evaluator);

	c_optimizer.vInitialize();

	for (int i = 0; i < ITERATIONS; i++)
	{
		ga.runIteration();
		cout<< ga.getBestFitness()<<endl;;
	}
	c_optimizer.vRunIteration();

	delete pc_evaluator;


	return 0;
}
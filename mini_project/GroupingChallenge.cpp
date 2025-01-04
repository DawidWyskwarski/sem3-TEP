#include "GaussianGroupingEvaluatorFactory.h"
#include "GroupingEvaluator.h"
#include "Optimizer.h"

using namespace GroupingChallenge;

int main()
{
	GaussianGroupingEvaluatorFactory evaluatorFactory(5, 100);

	evaluatorFactory
		.addDimension(-100, 100, 1.0, 1.0)
		.addDimension(-100, 100, 1.0, 1.0)
		.addDimension(-100, 100, 1.0, 1.0)
		.addDimension(-100, 100, 1.0, 1.0)
		.addDimension(-100, 100, 1.0, 1.0)
		.addDimension(-100, 100, 1.0, 1.0)
		.addDimension(-100, 100, 1.0, 1.0)
		.addDimension(-100, 100, 1.0, 1.0)
		.addDimension(-100, 100, 1.0, 1.0)
		.addDimension(-100, 100, 1.0, 1.0);

	GroupingEvaluator* evaluator = evaluatorFactory.createEvaluator(0);

	Optimizer optimizer(*evaluator);

	optimizer.initialize();

	for (int i = 0; i < 10; i++)
	{
		optimizer.runIteration();
	}

	delete evaluator;

	return 0;
}
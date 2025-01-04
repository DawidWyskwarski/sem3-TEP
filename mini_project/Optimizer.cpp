#include "Optimizer.h"

using namespace GroupingChallenge;

Optimizer::Optimizer(GroupingEvaluator& evaluator)
	: evaluator(evaluator)
{
	random_device seedGenerator;
	randomEngine.seed( seedGenerator() );
}

void Optimizer::initialize()
{
	numeric_limits<double> doubleLimits;
	currentBestFitness = doubleLimits.max();

	currentBest.clear();
	currentBest.resize(evaluator.getNumberOfPoints() );
}

void Optimizer::runIteration()
{
	vector<int> candidate( evaluator.getNumberOfPoints() );

	uniform_int_distribution<int> candidateDistribution(evaluator.getLowerBound(), evaluator.getUpperBound() );

	for (size_t i = 0; i < candidate.size(); i++)
	{
		candidate[i] = candidateDistribution(randomEngine);
	}

	double candidateFitness = evaluator.evaluate( candidate );

	if ( candidateFitness < currentBestFitness )
	{
		currentBest = candidate;
		currentBestFitness = candidateFitness;
	}

	cout << currentBestFitness << endl;
}
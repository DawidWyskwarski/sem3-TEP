#ifndef OPTIMIZER_H
#define OPTIMIZER_H

#include "GroupingEvaluator.h"

#include <iostream>
#include <numeric>
#include <random>
#include <vector>

using namespace std;

namespace GroupingChallenge
{
	class Optimizer
	{
	public:
		Optimizer(GroupingEvaluator& evaluator);

		void initialize();
		void runIteration();

		vector<int>* getCurrentBest() { return &currentBest; }

	private:
		GroupingEvaluator& evaluator;

		double currentBestFitness;
		vector<int> currentBest;

		mt19937 randomEngine;
	};
}

#endif
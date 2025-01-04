#ifndef GAUSSIAN_GROUPING_EVALUATOR_FACTORY_H
#define GAUSSIAN_GROUPING_EVALUATOR_FACTORY_H

#include "GroupingEvaluator.h"
#include "Point.h"

#include <random>
#include <vector>

using namespace std;

namespace GroupingChallenge
{
	class Dimension
	{
	public:
		Dimension(double meanMin, double meanMax, double standardDeviationMin, double standardDeviationMax, mt19937& randomEngine);

		double generateRandomMean();
		double generateRandomStandardDeviation();

	private:
		const double DEFAULT_STANDARD_DEVIATION_VALUE = 1.0;

		uniform_real_distribution<double> meanUniformDistribution;
		uniform_real_distribution<double> standardDeviationUniformDistribution;
		mt19937& randomEngine;
	};

	class GaussianDistribution
	{
	public:
		GaussianDistribution(double mean, double standardDeviation, mt19937& randomEngine);

		double generateRandomNumber();

	private:
		normal_distribution<double> normalDistribution;
		mt19937& randomEngine;
	};

	class GaussianGroupingEvaluatorFactory
	{
	public:
		GaussianGroupingEvaluatorFactory(int numberOfGroups, int numberOfPoints);

		GaussianGroupingEvaluatorFactory& addDimension(double meanMin, double meanMax, double standardDeviationMin, double standardDeviationMax);

		GroupingEvaluator* createEvaluator();
		GroupingEvaluator* createEvaluator(unsigned int seed);

	private:
		const int NUMBER_OF_GROUPS_MIN_VALUE = 1;
		const int NUMBER_OF_POINTS_MIN_VALUE = 1;

		vector<GaussianDistribution>* createGaussianDistributions();
		vector<Point>* createPoints(vector<GaussianDistribution>& gaussianDistributions);

		int numberOfGroups;
		int numberOfPoints;

		vector<Dimension> dimensions;
		mt19937 randomEngine;
	};
}

#endif
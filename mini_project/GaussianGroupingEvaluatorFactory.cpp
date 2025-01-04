#include "GaussianGroupingEvaluatorFactory.h"

using namespace GroupingChallenge;

Dimension::Dimension(double meanMin, double meanMax, double standardDeviationMin, double standardDeviationMax, mt19937 &randomEngine)
	: meanUniformDistribution(min(meanMin, meanMax), max(meanMin, meanMax)),
	standardDeviationUniformDistribution(min(standardDeviationMin, standardDeviationMax), max(standardDeviationMin, standardDeviationMax)),
	randomEngine(randomEngine)
{}

double Dimension::generateRandomMean(){
	return meanUniformDistribution(randomEngine);
}

double Dimension::generateRandomStandardDeviation(){

	double standardDeviation = standardDeviationUniformDistribution(randomEngine);

	if (standardDeviation <= 0)
	{
		standardDeviation = DEFAULT_STANDARD_DEVIATION_VALUE;
	}

	return standardDeviation;
}

GaussianDistribution::GaussianDistribution(double mean, double standardDeviation, mt19937& randomEngine)
	: normalDistribution(mean, standardDeviation), randomEngine(randomEngine)
{}

double GaussianDistribution::generateRandomNumber(){
	return normalDistribution(randomEngine);
}

GaussianGroupingEvaluatorFactory::GaussianGroupingEvaluatorFactory(int numberOfGroups, int numberOfPoints)
	: numberOfGroups(max(numberOfGroups, NUMBER_OF_GROUPS_MIN_VALUE)), numberOfPoints(max(numberOfPoints, NUMBER_OF_POINTS_MIN_VALUE))
{}

GaussianGroupingEvaluatorFactory& GaussianGroupingEvaluatorFactory::addDimension(double meanMin, double meanMax, double standardDeviationMin, double standardDeviationMax){
	dimensions.push_back(Dimension(meanMin, meanMax, standardDeviationMin, standardDeviationMax, randomEngine));

	return *this;
}

GroupingEvaluator* GaussianGroupingEvaluatorFactory::createEvaluator(){
	random_device seedGenerator;

	return createEvaluator(seedGenerator());
}

GroupingEvaluator* GaussianGroupingEvaluatorFactory::createEvaluator(unsigned int seed){
	randomEngine.seed(seed);

	vector<GaussianDistribution>* gaussianDistributions = createGaussianDistributions();
	vector<Point>* points = createPoints(*gaussianDistributions);

	GroupingEvaluator* evaluator = new GroupingEvaluator(numberOfGroups, *points);

	delete gaussianDistributions;
	delete points;

	return evaluator;
}


vector<GaussianDistribution>* GaussianGroupingEvaluatorFactory::createGaussianDistributions(){

	vector<GaussianDistribution>* gaussianDistributions = new vector<GaussianDistribution>();

	gaussianDistributions->reserve(dimensions.size());

	for (size_t i = 0; i < dimensions.size(); i++)
	{
		gaussianDistributions->push_back(GaussianDistribution(dimensions[i].generateRandomMean(), dimensions[i].generateRandomStandardDeviation(), randomEngine));
	}

	return gaussianDistributions;
}

vector<Point>* GaussianGroupingEvaluatorFactory::createPoints(vector<GaussianDistribution>& gaussianDistributions)
{
	vector<Point>* points = new vector<Point>();

	points->reserve(numberOfPoints);

	for (int i = 0; i < numberOfPoints; i++)
	{
		Point point;

		for (size_t j = 0; j < gaussianDistributions.size(); j++)
		{
			point.addCoordinate(gaussianDistributions[j].generateRandomNumber());
		}

		points->push_back(point);
	}

	return points;
}
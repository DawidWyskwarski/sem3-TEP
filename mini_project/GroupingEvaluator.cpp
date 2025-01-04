#include "GroupingEvaluator.h"

using namespace GroupingChallenge;

GroupingEvaluator::GroupingEvaluator(int numberOfGroups, const vector<Point>& points)
	: numberOfGroups(numberOfGroups), points(points)
{}

double GroupingEvaluator::evaluate(const int* solution) const{
	bool error = !solution || points.empty();

	double distance;
	double distanceSum = 0;

	for (size_t i = 0; i + 1 < points.size() && !error; i++){
		if (solution[i] >= getLowerBound() && solution[i] <= getUpperBound()){
			for (size_t j = i + 1; j < points.size(); j++){
				if (solution[i] == solution[j]){
					distance = points[i].calculateDistance(points[j]);

					if (distance >= 0){
						distanceSum += 2.0 * points[i].calculateDistance(points[j]);
					}
					else{
						error = true;
					}
				}
			}
		}else{
			error = true;
		}
	}

	if (error){
		return WRONG_VALUE;
	}

	return distanceSum;
}

double GroupingEvaluator::evaluate(const vector<int>* solution) const{

	if (!solution){
		return WRONG_VALUE;
	}

	return evaluate(*solution);
}

double GroupingEvaluator::evaluate(const vector<int>& solution) const {

	if (solution.size() != points.size()){
		return WRONG_VALUE;
	}

	return evaluate(solution.data());
}
#ifndef GROUPING_EVALUATOR_H
#define GROUPING_EVALUATOR_H

#include "Point.h"

#include <vector>

using namespace std;

namespace GroupingChallenge
{
	class GroupingEvaluator
	{
	public:
		GroupingEvaluator(int numberOfGroups, const vector<Point>& points);

		double evaluate(const int* solution) const;
		double evaluate(const vector<int>* solution) const;
		double evaluate(const vector<int>& solution) const;

		int getNumberOfPoints() const { return (int) points.size(); };

		int getLowerBound() const { return 1; };
		int getUpperBound() const { return numberOfGroups; }

	private:
		const double WRONG_VALUE = -1;

		int numberOfGroups;
		vector<Point> points;
	};
}

#endif
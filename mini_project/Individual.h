//
// Created by wyskw on 21.01.2025.
//

#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H
#include <vector>
#include "GroupingEvaluator.h"
#include <random>

class Individual {
public:
    Individual();

    Individual(const std::vector<int> &genes);

    Individual(const Individual &other);
    Individual(Individual&& other) noexcept;

    Individual& operator=(const Individual &other);
    Individual& operator=(Individual&& other) noexcept;

    ~Individual();

    double fitness(const NGroupingChallenge::CGroupingEvaluator &evaluator) const;
    void mutate(const double &mutationChance,const int &numberOfGroups);
    std::vector<Individual> cross(const Individual &partner, const double &crossingChance);

private:
    std::vector<int> genotype;
};

#endif //INDIVIDUAL_H

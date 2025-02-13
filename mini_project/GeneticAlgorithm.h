//
// Created by wyskw on 22.01.2025.
//

#ifndef GENETICALGORITHM_H
#define GENETICALGORITHM_H
#include "Individual.h"

using namespace NGroupingChallenge;

class GeneticAlgorithm {
public:

    GeneticAlgorithm(int populationSize,double crossingChance,double mutationChance, CGroupingEvaluator &evaluator);

    GeneticAlgorithm(const GeneticAlgorithm &other);
    GeneticAlgorithm(GeneticAlgorithm &&other) noexcept;

    GeneticAlgorithm& operator=(const GeneticAlgorithm &other);
    GeneticAlgorithm& operator=(GeneticAlgorithm &&other) noexcept;

    ~GeneticAlgorithm();

    void runIteration();

    [[nodiscard]] double getBestFitness() const;
    Individual getBestIndividual();

private:
    void initializeThePopulation();
    void findBest();

    [[nodiscard]] Individual chooseParent();

    int populationSize;
    double crossingChance;
    double mutationChance;

    mt19937 gen;

    Individual bestIndividual;
    double bestFitness;

    vector<Individual> population;

    CGroupingEvaluator& evaluator;
};

#endif //GENETICALGORITHM_H

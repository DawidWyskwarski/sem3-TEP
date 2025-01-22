//
// Created by wyskw on 22.01.2025.
//

#include "GeneticAlgorithm.h"

#include <cfloat>

using namespace NGroupingChallenge;

GeneticAlgorithm::GeneticAlgorithm(const int populationSize, const double crossingChance, const double mutationChance, CGroupingEvaluator& evaluator)
:populationSize(populationSize), crossingChance(crossingChance), mutationChance(mutationChance), bestFitness(DBL_MAX), evaluator(evaluator) { initializeThePopulation(); }

GeneticAlgorithm::GeneticAlgorithm(const GeneticAlgorithm &other) = default;

GeneticAlgorithm::GeneticAlgorithm(GeneticAlgorithm&& other) noexcept
:populationSize(other.populationSize), crossingChance(other.crossingChance), mutationChance(other.mutationChance), bestIndividual(std::move(other.bestIndividual)),
bestFitness(other.bestFitness), population(std::move(other.population)), evaluator(other.evaluator) {}

GeneticAlgorithm &GeneticAlgorithm::operator=(const GeneticAlgorithm &other) {
    if (this == &other)
        return *this;

    populationSize = other.populationSize;
    crossingChance = other.crossingChance;
    mutationChance = other.mutationChance;
    bestIndividual = other.bestIndividual;
    bestFitness = other.bestFitness;
    population = other.population;

    return *this;
}

GeneticAlgorithm &GeneticAlgorithm::operator=(GeneticAlgorithm &&other) noexcept {
    if (this == &other)
        return *this;

    populationSize = other.populationSize;
    crossingChance = other.crossingChance;
    mutationChance = other.mutationChance;
    bestIndividual = std::move(other.bestIndividual);
    bestFitness = other.bestFitness;
    population = std::move(other.population);

    return *this;
}

GeneticAlgorithm::~GeneticAlgorithm() = default;

void GeneticAlgorithm::initializeThePopulation() {

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> candidateDistribution(evaluator.iGetLowerBound(),evaluator.iGetUpperBound());

    const int numberOfPoints = evaluator.iGetNumberOfPoints();

    for(int i=0;i<populationSize;++i) {
        std::vector<int> individual(numberOfPoints);

        for(int j=0;j<numberOfPoints;++j) {
            individual[j] = candidateDistribution(gen);
        }
        population.emplace_back(individual);
    }

    findBest();
}

double GeneticAlgorithm::getBestFitness() const {
    return bestFitness;
}

Individual GeneticAlgorithm::getBestIndividual() {
    return bestIndividual;
}

void GeneticAlgorithm::findBest() {

    for(int i=0;i<populationSize;++i) {
        double currentFitness = population.at(i).fitness(evaluator);

        if(currentFitness < bestFitness) {
            bestFitness = currentFitness;
            bestIndividual = population.at(i);
        }
    }
}

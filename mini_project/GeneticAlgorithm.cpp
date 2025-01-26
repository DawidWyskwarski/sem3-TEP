//
// Created by wyskw on 22.01.2025.
//

#include "GeneticAlgorithm.h"

#include <cfloat>
#include <chrono>
#include <iostream>
#include <thread>

using namespace NGroupingChallenge;

GeneticAlgorithm::GeneticAlgorithm(const int populationSize, const double crossingChance, const double mutationChance, CGroupingEvaluator& evaluator)
:populationSize(populationSize), crossingChance(crossingChance), mutationChance(mutationChance), bestFitness(DBL_MAX), evaluator(evaluator) {

    std::random_device rd;
    gen.seed(rd());

    initializeThePopulation();
}

GeneticAlgorithm::GeneticAlgorithm(const GeneticAlgorithm &other): populationSize(other.populationSize),
  crossingChance(other.crossingChance), mutationChance(other.mutationChance), bestIndividual(other.bestIndividual),
  bestFitness(other.bestFitness), population(other.population), evaluator(other.evaluator){

    std::random_device rd;
    gen.seed(rd());
};

GeneticAlgorithm::GeneticAlgorithm(GeneticAlgorithm&& other) noexcept
:populationSize(other.populationSize), crossingChance(other.crossingChance), mutationChance(other.mutationChance), bestIndividual(std::move(other.bestIndividual)),
bestFitness(other.bestFitness), population(std::move(other.population)), evaluator(other.evaluator) {
    std::random_device rd;
    gen.seed(rd());
}

GeneticAlgorithm &GeneticAlgorithm::operator=(const GeneticAlgorithm &other) {
    if (this == &other)
        return *this;

    populationSize = other.populationSize;
    crossingChance = other.crossingChance;
    mutationChance = other.mutationChance;
    bestIndividual = other.bestIndividual;
    bestFitness = other.bestFitness;
    population = other.population;

    std::random_device rd;
    gen.seed(rd());

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

    std::random_device rd;
    gen.seed(rd());

    return *this;
}

GeneticAlgorithm::~GeneticAlgorithm() = default;

void GeneticAlgorithm::runIteration() {

    vector<Individual> newPopulation;
    newPopulation.reserve(populationSize);

    int newPopulationSize = 0;

    while(newPopulationSize < populationSize) {

        Individual parent1 = chooseParent();
        Individual parent2 = chooseParent();

        vector<Individual> children = parent1.cross(parent2, crossingChance);

        children.at(0).mutate(mutationChance, evaluator.iGetUpperBound());
        children.at(1).mutate(mutationChance, evaluator.iGetUpperBound());

        newPopulation.emplace_back(children.at(0));

        if(newPopulationSize+1<populationSize) {
            newPopulation.emplace_back(children.at(1));
        }

        newPopulationSize+=2;
    }

    population = std::move(newPopulation);

    findBest();
}

void GeneticAlgorithm::initializeThePopulation() {

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

Individual GeneticAlgorithm::chooseParent(){

    std::uniform_int_distribution<> index(0,populationSize-1);

    Individual parent1 = population.at(index(gen));
    Individual parent2 = population.at(index(gen));

    if ( parent1.fitness(evaluator) < parent2.fitness(evaluator) )
        return parent1;

    return parent2;
}

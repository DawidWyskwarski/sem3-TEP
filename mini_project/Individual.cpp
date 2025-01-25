//
// Created by wyskw on 21.01.2025.
//

#include "Individual.h"

#include <iostream>

Individual::Individual() = default;

Individual::Individual(const std::vector<int> &genes):genotype(genes) {}

Individual::Individual(const Individual &other):genotype(other.genotype) {}

Individual::Individual(Individual &&other) noexcept:genotype(std::move(other.genotype)) {}

Individual& Individual::operator=(const Individual &other) {
    if(this != &other) {
        genotype = other.genotype;
    }
    return *this;
}

Individual &Individual::operator=(Individual &&other) noexcept {
    if (this != &other) {
        genotype = std::move(other.genotype);
    }
    return *this;
}

Individual::~Individual() = default;

double Individual::fitness(const NGroupingChallenge::CGroupingEvaluator &evaluator) const {
    return evaluator.dEvaluate(genotype);
}

void Individual::mutate(const double &mutationChance,const int &numberOfGroups) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> mutDis(0.0,1.0);
    std::uniform_int_distribution<> groupDis(1, numberOfGroups);

    for(int &gene : genotype) {
        if(mutDis(gen) < mutationChance) {
            gene = groupDis(gen);
        }
    }
}

std::vector<Individual> Individual::cross(const Individual &partner, const double &crossingChance) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);

    std::vector<Individual> children;

    if (dis(gen) > crossingChance) {
        children.push_back(*this);
        children.push_back(partner);
    } else {

        const int n = genotype.size();

        std::uniform_int_distribution<> cutPointDis(1, n - 1);
        const int cutPoint = cutPointDis(gen);

        std::vector<int> child1, child2;

        child1.insert(child1.end(), genotype.begin(), genotype.begin() + cutPoint);
        child1.insert(child1.end(), partner.genotype.begin() + cutPoint, partner.genotype.end());

        child2.insert(child2.end(), partner.genotype.begin(), partner.genotype.begin() + cutPoint);
        child2.insert(child2.end(), genotype.begin() + cutPoint, genotype.end());

        children.emplace_back(child1);
        children.emplace_back(child2);
    }

    return children;
}

string Individual::toString() {

    string result;

    for(int i:genotype) {
        result+= '0'+ i;
    }

    return result;
}

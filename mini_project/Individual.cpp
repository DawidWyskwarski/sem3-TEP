//
// Created by wyskw on 21.01.2025.
//

#include "Individual.h"

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

std::vector<Individual> Individual::cross(const Individual &partner,const double &crossingChance) {

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> crossDis(0.0,1.0);
    std::vector<Individual> children;
    children.reserve(2);

    if(crossDis(gen) > crossingChance || genotype.size() == 1) {
        children.emplace_back(partner);
        children.emplace_back(*this);

        return children;
    }

    std::uniform_int_distribution<> groupDis( 1, genotype.size()-1 );

    int pivot = groupDis(gen);

    Individual child1;
    Individual child2;

    for(int i=0; i<pivot; ++i) {
        child1.genotype.emplace_back( this->genotype.at(i) );
        child2.genotype.emplace_back( partner.genotype.at(i) );
    }

    for(int i=pivot;i<genotype.size();++i) {
        child1.genotype.emplace_back( partner.genotype.at(i) );
        child2.genotype.emplace_back( this->genotype.at(i) );
    }

    children.emplace_back(child1);
    children.emplace_back(child2);

    return children;
}

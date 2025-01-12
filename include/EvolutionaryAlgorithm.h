#ifndef EVOLUTIONARYALGORITHM_H
#define EVOLUTIONARYALGORITHM_H
#include <float.h>
#include <vector>

#include "ObjectiveFunction.h"

struct Individual
{
    static constexpr double deviation_ratio = 0.5;

    double x;
    double y;
    double fitness;

    void printIndividual() const;
    void calculateFitness(ObjectiveFunctions objective_function_selector);
    Individual getDeviatedIndividual() const;


    void setIndividualFrom(const Individual &other);
    Individual(const Individual *other);
    Individual(double x, double y);
    Individual(double x, double y, double fitness);

    bool operator <(const Individual &other) const;
    bool operator >(const Individual &other) const;

};

class EvolutionaryAlgorithm
{
private:
    static constexpr unsigned int population_size = 100;
    static constexpr unsigned int procreator_size = 50;

    unsigned int generation_limit;
    unsigned int termination_limit;
    ObjectiveFunctions objective_function_selector = ObjectiveFunctions::ALL;

    unsigned int generation_counter = 0;
    unsigned int same_best_individual_counter = 0;

    double previous_best_individual = DBL_MAX;
    std::vector<Individual*> population = std::vector<Individual*>(population_size * 2);

    void variation();
    void fitnessEvaluation();
    void sortPopulation();
    void generationalCalculation();

public:
    void printGeneration() const;
    void printPopulation() const;
    EvolutionaryAlgorithm(const int generation_limit, const int termination_limit, const ObjectiveFunctions objective_function_selector);
    void run();
    ~EvolutionaryAlgorithm();

};

#endif //EVOLUTIONARYALGORITHM_H

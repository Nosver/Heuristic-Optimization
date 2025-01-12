#include "../include/EvolutionaryAlgorithm.h"

#include <cfloat>
#include <iostream>

#include "../include/ObjectiveFunction.h"
#include "../include/utils.h"

void Individual::printIndividual() const
{
    std::cout << this << "\t x: " << x << "\t y: " << y << "\t fitness: " << fitness << std::endl;
}

void Individual::calculateFitness(const ObjectiveFunctions objective_function_selector)
{
    this->fitness = ObjectiveFunction::objectiveFunction(x, y, objective_function_selector);
}

Individual Individual::getDeviatedIndividual() const
{
    Individual child(this);
    const double deviation_probability = utils::getRandomDouble(0.0, 1.0);
    int deviation_amount = 1;
    if (deviation_probability < deviation_ratio)
    {
        deviation_amount = 2;
    }

    // Deviate only 1 decision variable
    if (deviation_amount == 1)
    {
        // Choose what variable to deviate
        if (utils::getRandomInt(0, 1))
        {
            child.x = utils::deviateDecisionVariableWithNormalDistribution(this->x, -5.0, 5.0);
        }
        else
        {
            child.y = utils::deviateDecisionVariableWithNormalDistribution(this->y, -5.0, 5.0);
        }
    }

    // Deviate 2 decision variables
    else
    {
        child.x = utils::deviateDecisionVariableWithNormalDistribution(this->x, -5.0, 5.0);
        child.y = utils::deviateDecisionVariableWithNormalDistribution(this->y, -5.0, 5.0);
    }
    return child;
}

void Individual::setIndividualFrom(const Individual& other)
{
    this->x = other.x;
    this->y = other.y;
    this->fitness = other.fitness;
}

Individual::Individual(const Individual *other)
{
    this->x = other->x;
    this->y = other->y;
    this->fitness = other->fitness;
}

Individual::Individual(const double x, const double y)
{
    this->x = x;
    this->y = y;
    this->fitness = DBL_MAX;
}

Individual::Individual(double x, double y, double fitness)
{
    this->x = x;
    this->y = y;
    this->fitness = fitness;
}

bool Individual::operator<(const Individual& other) const
{
    return this->fitness < other.fitness;
}

bool Individual::operator>(const Individual& other) const
{
    return this->fitness > other.fitness;
}

void EvolutionaryAlgorithm::variation()
{
    for (int i=0; i < population_size; i++)
    {
        const Individual child = population[i % procreator_size]->getDeviatedIndividual();
        population[population_size + i]->x = child.x;
        population[population_size + i]->y = child.y;
    }
}

void EvolutionaryAlgorithm::fitnessEvaluation()
{
    for (int i=0; i < population_size * 2; i++)
    {
        population[i]->calculateFitness(objective_function_selector);
    }
}

void EvolutionaryAlgorithm::sortPopulation()
{
    std::sort(population.begin(), population.end(), [](const Individual* a, const Individual* b) {
        return *a < *b;
    });
}

void EvolutionaryAlgorithm::generationalCalculation()
{
    // Check same best individual counter
    if (previous_best_individual == population[0]->fitness)
    {
        same_best_individual_counter++;
    }
    else
    {
        same_best_individual_counter = 0;
    }

    previous_best_individual = population[0]->fitness;
}

void EvolutionaryAlgorithm::printGeneration() const
{
    std::cout << "Generation: " << generation_counter << std::endl;
    std::cout << "Same Best Individual Counter: " << same_best_individual_counter << std::endl;
    std::cout << "Best individual:\t";
    population[0]->printIndividual();
    std::cout << "\n";
}

void EvolutionaryAlgorithm::printPopulation() const
{
    std::cout << "Generation: " << generation_counter << std::endl;
    for (int i=0; i < population_size * 2; i++)
    {
        std::cout << "[" << i << "]: ";
        population[i]->printIndividual();
    }
    std::cout << "\n\n";
}

EvolutionaryAlgorithm::EvolutionaryAlgorithm(const int generation_limit, const int termination_limit, const ObjectiveFunctions objective_function_selector)
{
    this->generation_limit = generation_limit;
    this->termination_limit = termination_limit;
    this->objective_function_selector = objective_function_selector;

    // Initialize random generation of individuals
    for (int i=0; i < population_size * 2; i++)
    {
        const double x = utils::getRandomDouble(-5.0, 5.0);
        const double y = utils::getRandomDouble(-5.0, 5.0);
        population[i] = new Individual(x, y);
    }
}

void EvolutionaryAlgorithm::run()
{
    for (int i=0; i < generation_limit ; i++)
    {
        variation();
        fitnessEvaluation();
        sortPopulation();
        generationalCalculation();
        printGeneration();
        generation_counter++;

        if (same_best_individual_counter >= termination_limit)
        {
            std::cout << "Termination limit reached: " << termination_limit << std::endl;
            break;
        }
    }
}

EvolutionaryAlgorithm::~EvolutionaryAlgorithm()
{
    for (int i=0; i < population_size * 2; i++)
    {
        delete population[i];
    }
}


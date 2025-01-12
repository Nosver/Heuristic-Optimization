#include "../include/ObjectiveFunction.h"
#include <iostream>

#include "../include/EvolutionaryAlgorithm.h"
#include "../include/utils.h"

int main()
{
    EvolutionaryAlgorithm ea(1000, 10, ObjectiveFunctions::ALL);
    ea.run();

    return 0;
}


#include "../include/ObjectiveFunction.h"
#include <cmath>
#include <cfloat>
#include <functional>
#include <iostream>
#include <limits>

double ObjectiveFunction::rastiginFunction(const double x1, const double x2)
{
    constexpr double A = 10.0;

    double result = A * 2;

    result += x1 * x1 - A * std::cos(2 * M_PI * x1);
    result += x2 * x2 - A * std::cos(2 * M_PI * x2);

    return result;
}

double ObjectiveFunction::ackleyFunction(const double x, const double y)
{
    constexpr double A = -20.0;

    const double term1 = std::exp(-0.2 * std::sqrt(0.5 * (x * x + y * y)));
    const double term2 = std::exp(0.5 * (std::cos(2 * M_PI * x) + std::cos(2 * M_PI * y)));

    return A * term1 * term2 + std::exp(1.0) + 20.0;
}

double ObjectiveFunction::sphereFunction(const double x, const double y)
{
    return x*x + y*y;
}

double ObjectiveFunction::rosenbrockFunction(const double x, const double y)
{
    return 100.0 * pow((y - pow(x, 2)), 2) + pow(1 - x, 2);
}

double ObjectiveFunction::boothFunction(const double x, const double y)
{
    const double term1 = std::pow(x + 2 * y - 7, 2);
    const double term2 = std::pow(2 * x + y - 5, 2);
    return term1 + term2;
}

double ObjectiveFunction::matyasFunction(const double x, const double y)
{
    return 0.26 * (x * x + y * y) - 0.48 * x * y;
}

double ObjectiveFunction::leviFunction(const double x, const double y)
{
    return std::pow(std::sin(3 * M_PI * x), 2) +
         std::pow(x - 1, 2) * (1 + std::pow(std::sin(3 * M_PI * y), 2)) +
         std::pow(y - 1, 2) * (1 + std::pow(std::sin(2 * M_PI * y), 2));
}

double ObjectiveFunction::griewankFunction(const double x, const double y) {

    double sum_squares = x * x + y * y;
    double product_cosines = std::cos(x) * std::cos(y / std::sqrt(2));

    return 1 + sum_squares / 4000 - product_cosines;
}

double ObjectiveFunction::himmelblauFunction(const double x, const double y)
{
    double term1 = std::pow(x * x + y - 11, 2);
    double term2 = std::pow(x + y * y - 7, 2);

    return term1 + term2;
}

double ObjectiveFunction::threeHumpCamelFunction(const double x, const double y)
{
    return 2 * x * x - 1.05 * std::pow(x, 4) + std::pow(x, 6) / 6 + x * y + y * y;
}

std::function<double(double, double)> ObjectiveFunction::selectorFunction(const double x1, const double x2, ObjectiveFunctions objective_function)
{
    int param = static_cast<int>(x1 * x2);
    ObjectiveFunctions selector = objective_function;

    if (objective_function == ObjectiveFunctions::ALL)
    {
        selector = static_cast<ObjectiveFunctions>(abs(param) % static_cast<int>(ObjectiveFunctions::ALL));
    }

    switch (selector)
    {
    case ObjectiveFunctions::RASTIGIN:
        // std::cout << "rastiginFunction" << std::endl;
            return rastiginFunction;
    case ObjectiveFunctions::ACKLEY:
        // std::cout << "ackleyFunction" << std::endl;
            return ackleyFunction;
    case ObjectiveFunctions::SPHERE:
        // std::cout << "sphereFunction" << std::endl;
            return sphereFunction;
    case ObjectiveFunctions::ROSENBROCK:
        // std::cout << "rosenbrockFunction" << std::endl;
            return rosenbrockFunction;
    case ObjectiveFunctions::BOOTH:
        // std::cout << "boothFunction" << std::endl;
            return boothFunction;
    case ObjectiveFunctions::MATYAS:
        // std::cout << "matyasFunction" << std::endl;
            return matyasFunction;
    case ObjectiveFunctions::LEVI:
        // std::cout << "leviFunction" << std::endl;
            return leviFunction;
    case ObjectiveFunctions::GRIEWANK:
        // std::cout << "griewankFunction" << std::endl;
            return griewankFunction;
    case ObjectiveFunctions::HIMMELBLAU:
        // std::cout << "himmelblauFunction" << std::endl;
            return himmelblauFunction;
    case ObjectiveFunctions::THREE_HUMP_CAMEL:
        // std::cout << "threeHumpCamelFunction" << std::endl;
            return threeHumpCamelFunction;
    default:
        throw std::invalid_argument("Invalid function selector. Check the selector_modulo value.");
    }
}

double ObjectiveFunction::objectiveFunction(const double x1, const double x2, ObjectiveFunctions objective_function_number)
{
    if(x1 < M_MIN_BOUND || x1 > M_MAX_BOUND || x2 < M_MIN_BOUND || x2 > M_MAX_BOUND) {
        // std::cout << "Out of bound parameters. Returning DBL_MAX." << std::endl;
        return std::numeric_limits<double>::max();
    }

    const auto function = selectorFunction(x1, x2, objective_function_number);
    try
    {
        return function(x1, x2);
    }
    catch (...)
    {
        // std::cout << "Function returned undefined value. Using DBL_MAX instead." << std::endl;
        return DBL_MAX;
    }
}

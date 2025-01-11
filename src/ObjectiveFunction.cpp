#include "../include/ObjectiveFunction.h"
#include <cmath>
#include <cfloat>
#include <functional>
#include <iostream>

double ObjectiveFunction::sphereFunction(double x)
{
    return x * x;
}

double ObjectiveFunction::rastriginFunction(double x)
{
    return 10 + (x * x - 10 * std::cos(2 * M_PI * x));
}

double ObjectiveFunction::ackleyFunction(double x)
{
    return -20 * std::exp(-0.2 * std::sqrt(0.5 * (x * x))) - std::exp(0.5 * (std::cos(2 * M_PI * x))) + 20 + M_E;
}

double ObjectiveFunction::griewankFunction(double x)
{
    return 1 + (x * x) / 4000 - std::cos(x / std::sqrt(1));
}

double ObjectiveFunction::styblinskiTangFunction(double x)
{
    return 0.5 * (x * x * x * x - 16 * x * x + 5 * x);
}

double ObjectiveFunction::rosenbrockFunction(double x1, double x2)
{
    return 100 * std::pow((x2 - x1 * x1), 2) + std::pow((1 - x1), 2);
}

double ObjectiveFunction::bealeFunction(double x1, double x2)
{
    return std::pow((1.5 - x1 + x1 * x2), 2) + std::pow((2.25 - x1 + x1 * x2 * x2), 2) + std::pow((2.625 - x1 + x1 * x2 * x2 * x2), 2);
}

double ObjectiveFunction::goldsteinPriceFunction(double x1, double x2)
{
    return (1 + std::pow((x1 + x2 + 1), 2) * (19 - 14 * x1 + 3 * x1 * x1 - 14 * x2 + 6 * x1 * x2 + 3 * x2 * x2)) *
           (30 + std::pow((2 * x1 - 3 * x2), 2) * (18 - 32 * x1 + 12 * x1 * x1 + 48 * x2 - 36 * x1 * x2 + 27 * x2 * x2));
}

double ObjectiveFunction::boothFunction(double x1, double x2)
{
    return std::pow((x1 + 2 * x2 - 7), 2) + std::pow((2 * x1 + x2 - 5), 2);
}

double ObjectiveFunction::bukinN6Function(double x1, double x2)
{
    return 100 * std::sqrt(std::abs(x2 - 0.01 * x1 * x1)) + 0.01 * std::abs(x1 + 10);
}

double ObjectiveFunction::matyasFunction(double x1, double x2)
{
    return 0.26 * (x1 * x1 + x2 * x2) - 0.48 * x1 * x2;
}

double ObjectiveFunction::leviN13Function(double x1, double x2)
{
    return std::pow((std::sin(3 * M_PI * x1)), 2) + std::pow((x1 - 1), 2) * (1 + std::pow((std::sin(3 * M_PI * x2)), 2)) + std::pow((x2 - 1), 2) * (1 + std::pow((std::sin(2 * M_PI * x2)), 2));
}

double ObjectiveFunction::himmelblauFunction(double x1, double x2)
{
    return std::pow((x1 * x1 + x2 - 11), 2) + std::pow((x1 + x2 * x2 - 7), 2);
}

double ObjectiveFunction::threeHumpCamelFunction(double x1, double x2)
{
    return 2 * x1 * x1 - 1.05 * std::pow(x1, 4) + std::pow(x1, 6) / 6 + x1 * x2 + x2 * x2;
}

double ObjectiveFunction::easomFunction(double x1, double x2)
{
    return -std::cos(x1) * std::cos(x2) * std::exp(-std::pow((x1 - M_PI), 2) - std::pow((x2 - M_PI), 2));
}

double ObjectiveFunction::crossInTrayFunction(double x1, double x2)
{
    return -0.0001 * std::pow((std::abs(std::sin(x1) * std::sin(x2) * std::exp(std::abs(100 - std::sqrt(x1 * x1 + x2 * x2) / M_PI))) + 1), 0.1);
}

double ObjectiveFunction::eggholderFunction(double x1, double x2)
{
    return -(x2 + 47) * std::sin(std::sqrt(std::abs(x2 + x1 / 2 + 47))) - x1 * std::sin(std::sqrt(std::abs(x1 - (x2 + 47))));
}

double ObjectiveFunction::holderTableFunction(double x1, double x2)
{
    return -std::abs(std::sin(x1) * std::cos(x2) * std::exp(std::abs(1 - std::sqrt(x1 * x1 + x2 * x2) / M_PI)));
}

double ObjectiveFunction::mccormickFunction(double x1, double x2)
{
    return std::sin(x1 + x2) + std::pow((x1 - x2), 2) - 1.5 * x1 + 2.5 * x2 + 1;
}

double ObjectiveFunction::schafferFunction_n2(double x1, double x2)
{
    return 0.5 + (std::pow(std::sin(x1 * x1 - x2 * x2), 2) - 0.5) / std::pow((1 + 0.001 * (x1 * x1 + x2 * x2)), 2);
}

double ObjectiveFunction::schafferFunction_n4(double x1, double x2)
{
    return 0.5 + (std::pow(std::cos(std::sin(std::abs(x1 * x1 - x2 * x2))), 2) - 0.5) / std::pow((1 + 0.001 * (x1 * x1 + x2 * x2)), 2);
}

double ObjectiveFunction::chankongHaimesFunction(double x1, double x2)
{
    return 2 + (x1 - 2) * (x1 - 2) + (x2 - 1) * (x2 - 1);
}

double ObjectiveFunction::fonsecaFlemingFunction(double x1, double x2)
{
    return 1 - std::exp(-std::pow((x1 - 1 / std::sqrt(2)), 2) - std::pow((x2 - 1 / std::sqrt(2)), 2));
}

double ObjectiveFunction::test4Function(double x1, double x2)
{
    return std::pow((x1 - 2), 2) + std::pow((x2 - 2), 2);
}

double ObjectiveFunction::kursaweFunction(double x1, double x2)
{
    return -10 * std::exp(-0.2 * std::sqrt(x1 * x1 + x2 * x2));
}

double ObjectiveFunction::osyczkaKunduFunction(double x1, double x2)
{
    return -25 * (x1 - 2) * (x1 - 2) + (x2 - 1) * (x2 - 1);
}

double ObjectiveFunction::ctp1Function(double x1, double x2)
{
    return x1 + x2;
}

double ObjectiveFunction::constrExProblem(double x1, double x2)
{
    return x1 + x2;
}

double ObjectiveFunction::viennetFunction(double x1, double x2)
{
    return 0.5 * (x1 * x1 + x2 * x2) + std::sin(x1 * x1 + x2 * x2);
}

std::function<double(double, double)> ObjectiveFunction::selectorFunction(const double x1, const double x2)
{
    switch (const int selector = static_cast<int>(sphereFunction(x1) * rastriginFunction(x2)) % selector_modulo)
    {
    case 0:
        std::cout << "Rosenbrock Function" << std::endl;
        return rosenbrockFunction;
    case 1:
        std::cout << "Beale Function" << std::endl;
        return bealeFunction;
    case 2:
        std::cout << "Goldstein-Price Function" << std::endl;
        return goldsteinPriceFunction;
    case 3:
        std::cout << "Booth Function" << std::endl;
        return boothFunction;
    case 4:
        std::cout << "Bukin N6 Function" << std::endl;
        return bukinN6Function;
    case 5:
        std::cout << "Matyas Function" << std::endl;
        return matyasFunction;
    case 6:
        std::cout << "Levi N13 Function" << std::endl;
        return leviN13Function;
    case 7:
        std::cout << "Himmelblau Function" << std::endl;
        return himmelblauFunction;
    case 8:
        std::cout << "Three-Hump Camel Function" << std::endl;
        return threeHumpCamelFunction;
    case 9:
        std::cout << "Easom Function" << std::endl;
        return easomFunction;
    case 10:
        std::cout << "Cross-in-Tray Function" << std::endl;
        return crossInTrayFunction;
    case 11:
        std::cout << "Eggholder Function" << std::endl;
        return eggholderFunction;
    case 12:
        std::cout << "Holder Table Function" << std::endl;
        return holderTableFunction;
    case 13:
        std::cout << "McCormick Function" << std::endl;
        return mccormickFunction;
    case 14:
        std::cout << "Schaffer Function N2" << std::endl;
        return schafferFunction_n2;
    case 15:
        std::cout << "Schaffer Function N4" << std::endl;
        return schafferFunction_n4;
    case 16:
        std::cout << "Chankong-Haimes Function" << std::endl;
        return chankongHaimesFunction;
    case 17:
        std::cout << "Fonseca-Fleming Function" << std::endl;
        return fonsecaFlemingFunction;
    case 18:
        std::cout << "Test4 Function" << std::endl;
        return test4Function;
    case 19:
        std::cout << "Kursawe Function" << std::endl;
        return kursaweFunction;
    case 20:
        std::cout << "Osyczka-Kundu Function" << std::endl;
        return osyczkaKunduFunction;
    case 21:
        std::cout << "CTP1 Function" << std::endl;
        return ctp1Function;
    case 22:
        std::cout << "Constr-Ex Problem" << std::endl;
        return constrExProblem;
    case 23:
        std::cout << "Viennet Function" << std::endl;
        return viennetFunction;
    default:
        throw std::invalid_argument("Invalid function selector. Check the selector_modulo value.");
    }
}

double ObjectiveFunction::objectiveFunction(const double x1, const double x2)
{
    const auto function = selectorFunction(x1, x2);
    try
    {
        return function(x1, x2);
    }
    catch (...)
    {
        std::cout << "Function returned undefined value. Using DBL_MAX instead." << std::endl;
        return DBL_MAX;
    }
}

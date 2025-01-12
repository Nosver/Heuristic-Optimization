#ifndef OBJECTIVEFUNCTION_H
#define OBJECTIVEFUNCTION_H
#include <functional>
#include <sys/types.h>

constexpr double M_MIN_BOUND = -5.0;
constexpr double M_MAX_BOUND = 5.0;

enum class ObjectiveFunctions
{
    RASTIGIN,
    ACKLEY,
    SPHERE,
    ROSENBROCK,
    BOOTH,
    MATYAS,
    LEVI,
    GRIEWANK,
    HIMMELBLAU,
    THREE_HUMP_CAMEL,
    ALL
};

class ObjectiveFunction
{

private:

    static double rastiginFunction(double, double);
    static double ackleyFunction(double x, double y);
    static double sphereFunction(double x, double y);
    static double rosenbrockFunction(double x, double y);
    static double boothFunction(double x, double y);
    static double matyasFunction(double x, double y);
    static double leviFunction(double x, double y);
    static double griewankFunction(double x, double y);
    static double himmelblauFunction(double x, double y);
    static double threeHumpCamelFunction(double x, double y);

    static std::function<double(double, double)> selectorFunction(double, double, ObjectiveFunctions objective_function = ObjectiveFunctions::ALL);

public:
    static double objectiveFunction(double, double, ObjectiveFunctions objective_function_number = ObjectiveFunctions::ALL);

};


#endif //OBJECTIVEFUNCTION_H

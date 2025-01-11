#ifndef OBJECTIVEFUNCTION_H
#define OBJECTIVEFUNCTION_H
#include <functional>
#include <sys/types.h>

class ObjectiveFunction
{

private:

    static constexpr ushort selector_modulo = 24;

    static double sphereFunction(double);
    static double rastriginFunction(double);
    static double ackleyFunction(double);
    static double griewankFunction(double);
    static double styblinskiTangFunction(double);
    static double rosenbrockFunction(double, double);
    static double bealeFunction(double, double);
    static double goldsteinPriceFunction(double, double);
    static double boothFunction(double, double);
    static double bukinN6Function(double, double);
    static double matyasFunction(double, double);
    static double leviN13Function(double, double);
    static double himmelblauFunction(double, double);
    static double threeHumpCamelFunction(double, double);
    static double easomFunction(double, double);
    static double crossInTrayFunction(double, double);
    static double eggholderFunction(double, double);
    static double holderTableFunction(double, double);
    static double mccormickFunction(double, double);
    static double schafferFunction_n2(double, double);
    static double schafferFunction_n4(double, double);
    static double chankongHaimesFunction(double, double);
    static double fonsecaFlemingFunction(double, double);
    static double test4Function(double, double);
    static double kursaweFunction(double, double);
    static double osyczkaKunduFunction(double, double);
    static double ctp1Function(double, double);
    static double constrExProblem(double, double);
    static double viennetFunction(double, double);

    static std::function<double(double, double)> selectorFunction(double, double);

public:
    static double objectiveFunction(double, double);

};


#endif //OBJECTIVEFUNCTION_H

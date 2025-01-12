#ifndef UTILS_H
#define UTILS_H
#include <chrono>
#include <climits>
#include <random>

namespace utils
{

    // Random device
    inline std::random_device rd;
    inline std::mt19937 gen(rd() ? rd() : std::chrono::system_clock::now().time_since_epoch().count());
    inline std::uniform_int_distribution<> u_dis(0, INT_MAX);

    int getRandomInt(int min_val, int max_val);
    double getRandomDouble(double min_val, double max_val);
    double deviateDecisionVariableWithNormalDistribution(double mean, double min_val, double max_val);

}

#endif //UTILS_H

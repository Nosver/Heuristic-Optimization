#include "../include/utils.h"

// TC: O(1), SC: O(1)
int utils::getRandomInt(int min_val, int max_val)
{
    const int randomInt = u_dis(gen);
    if (max_val < min_val) { std::swap(min_val, max_val);}
    const int range = max_val - min_val + 1;
    return min_val + (randomInt % range);
}

// TC: O(1), SC: O(1)
double utils::getRandomDouble(const double min_val, const double max_val)
{
    const int randomInt = u_dis(gen);
    const double randomFraction = static_cast<double>(randomInt) / INT_MAX;
    const double randomDouble = min_val + randomFraction * (max_val - min_val);
    return randomDouble;
}

// TC: O(1), SC: O(1)
double utils::deviateDecisionVariableWithNormalDistribution(const double mean, const double min_val, const double max_val)
{
    const double stddev = (max_val - min_val) / 4;
    std::normal_distribution<> n_dis(mean, stddev);
    return n_dis(gen);
}

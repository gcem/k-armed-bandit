#pragma once

#include "TestBed.hpp"
#include <random>

class ConstantRewardTestBed : public TestBed
{
public:
    ConstantRewardTestBed(int arms,
                          int rounds,
                          double valueMean = 0,
                          double valueVariance = 1,
                          double rewardVariance = 1);

    TestResult test(BanditSolver* solver, int numberOfTests) override;

protected:
    /**
     * @brief Generates arm values about valueMean
     *
     */
    std::normal_distribution<double> valueDistribution;

    /**
     * @brief Generates rewards about ZERO. You must add the reward value.
     *
     */
    std::normal_distribution<double> rewardDistribution;

    int rounds;
};
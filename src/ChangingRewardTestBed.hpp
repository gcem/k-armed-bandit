#pragma once

#include "TestBed.hpp"
#include <random>

class ChangingRewardTestBed : public TestBed
{
public:
    ChangingRewardTestBed(int arms,
                          int rounds,
                          double initialValue = 0,
                          double walkVariance = 0.0001,
                          double rewardVariance = 1);

    TestResult test(BanditSolver* solver, int numberOfTests) override;

protected:
    /**
     * @brief Generates rewards about ZERO. You must add the reward value.
     *
     */
    std::normal_distribution<double> rewardDistribution;

    /**
     * @brief Generates rewards about ZERO. You must add the reward value.
     *
     */
    std::normal_distribution<double> walkDistribution;

    int rounds;
    double initialValue;
};
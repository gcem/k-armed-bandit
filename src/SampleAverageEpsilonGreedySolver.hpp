#pragma once

#include "EpsilonGreedySolver.hpp"

/**
 * @brief Tries a random arm with the probability Epsilon
 *
 */
class SampleAverageEpsilonGreedySolver : public EpsilonGreedySolver
{
public:
    SampleAverageEpsilonGreedySolver(int arms,
                                     double epsilon,
                                     double initialEstimates);

    void setReward(double reward) override;

    void reset() override;

protected:
    std::vector<int> choiceCount;
};
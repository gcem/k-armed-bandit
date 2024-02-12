#pragma once

#include "EpsilonGreedySolver.hpp"

/**
 * @brief Tries a random arm with the probability Epsilon
 *
 */
class ConstantStepSizeEpsilonGreedySolver : public EpsilonGreedySolver
{
public:
    ConstantStepSizeEpsilonGreedySolver(int arms,
                                        double epsilon,
                                        double initialEstimates,
                                        double stepSize);

    void setReward(double reward) override;

    void reset() override;

    double getAverageEstimate() override;

protected:
    double stepSize;
};
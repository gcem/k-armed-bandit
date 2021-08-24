#pragma once

#include "BanditSolver.hpp"
#include <vector>

/**
 * @brief Tries a random arm with the probability Epsilon
 *
 */
class EpsilonGreedySolver : public BanditSolver
{
public:
    EpsilonGreedySolver(int arms, double epsilon, double initialEstimates);

    int getChoice() override final;

    void reset() override;

protected:
    int lastChoice;

    double epsilon;

    /**
     * @brief Needed for reset()
     *
     */
    double initialEstimates;

    std::vector<double> valueEstimates;
};
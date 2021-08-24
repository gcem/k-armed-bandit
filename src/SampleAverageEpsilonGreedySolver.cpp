#include "SampleAverageEpsilonGreedySolver.hpp"

SampleAverageEpsilonGreedySolver::SampleAverageEpsilonGreedySolver(
  int arms,
  double epsilon,
  double initialEstimates)
  : EpsilonGreedySolver(arms, epsilon, initialEstimates)
  , round(0)
{}

void
SampleAverageEpsilonGreedySolver::setReward(double reward)
{
    round++;
    double sampleWeight = 1.0 / round;
    valueEstimates[lastChoice] =
      reward * sampleWeight + valueEstimates[lastChoice] * (1 - sampleWeight);
}

void
SampleAverageEpsilonGreedySolver::reset()
{
    round = 0;
    EpsilonGreedySolver::reset();
}

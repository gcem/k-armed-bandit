#include "SampleAverageEpsilonGreedySolver.hpp"

SampleAverageEpsilonGreedySolver::SampleAverageEpsilonGreedySolver(
  int arms,
  double epsilon,
  double initialEstimates)
  : EpsilonGreedySolver(arms, epsilon, initialEstimates)
  , choiceCount(arms, 0)
{}

void
SampleAverageEpsilonGreedySolver::setReward(double reward)
{
    choiceCount[lastChoice]++;
    double sampleWeight = 1.0 / choiceCount[lastChoice];
    valueEstimates[lastChoice] =
      reward * sampleWeight + valueEstimates[lastChoice] * (1 - sampleWeight);
}

void
SampleAverageEpsilonGreedySolver::reset()
{
    choiceCount = std::vector<int>(arms, 0);
    EpsilonGreedySolver::reset();
}

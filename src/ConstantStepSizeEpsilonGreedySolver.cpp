#include "ConstantStepSizeEpsilonGreedySolver.hpp"

ConstantStepSizeEpsilonGreedySolver::ConstantStepSizeEpsilonGreedySolver(
  int arms,
  double epsilon,
  double initialEstimates,
  double stepSize)
  : EpsilonGreedySolver(arms, epsilon, initialEstimates)
  , stepSize(stepSize)
{}

void
ConstantStepSizeEpsilonGreedySolver::setReward(double reward)
{
    valueEstimates[lastChoice] +=
      stepSize * (reward - valueEstimates[lastChoice]);
}

void
ConstantStepSizeEpsilonGreedySolver::reset()
{
    EpsilonGreedySolver::reset();
}

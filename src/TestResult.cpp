#include "TestResult.hpp"

TestResult::TestResult(int rounds)
  : averageReward(rounds, 0)
  , optimalChoices(rounds, 0)
{}

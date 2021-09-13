#include "ChangingRewardTestBed.hpp"
#include "Common.hpp"
#include <limits>
#include <iostream>

ChangingRewardTestBed::ChangingRewardTestBed(int arms,
                                             int rounds,
                                             double initialValue,
                                             double walkVariance,
                                             double rewardVariance)
  : TestBed(arms)
  , rounds(rounds),
  initialValue(initialValue)
{
    walkDistribution =
      std::normal_distribution<double>(0, sqrt(walkVariance));
    rewardDistribution = std::normal_distribution<double>(0, rewardVariance);
}

TestResult
ChangingRewardTestBed::test(BanditSolver* solver, int numberOfTests)
{
    TestResult result(rounds);

    for (int t = 0; t < numberOfTests; t++) {
        // create problem
        std::vector<double> values(arms);
        for (int arm = 0; arm < arms; arm++)
            values[arm] = 0;

        // make solver solve it
        solver->reset();
        for (int round = 0; round < rounds; round++) {
            double maxValue = std::numeric_limits<double>::lowest();
            int best = 0;
            for (int arm = 0; arm < arms; arm++)
                if (values[arm] > maxValue) {
                    maxValue = values[arm];
                    best = arm;
                }

            int choice = solver->getChoice();
            double reward = rewardDistribution(generator) + values[choice];
            solver->setReward(reward);

            if (choice == best)
                result.optimalChoices[round] += 1;
            result.averageReward[round] += reward;

            for (int i = 0; i < arms; i++) {
                values[i] += walkDistribution(generator);
            }
        }
    }
    
    // calculate averages
    for (int round = 0; round < rounds; round++) {
        result.optimalChoices[round] /= numberOfTests;
        result.averageReward[round] /= numberOfTests;
    }

    return result;
}

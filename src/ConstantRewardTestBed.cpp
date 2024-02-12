#include "ConstantRewardTestBed.hpp"
#include "Common.hpp"
#include <limits>

ConstantRewardTestBed::ConstantRewardTestBed(int arms,
                                             int rounds,
                                             double valueMean,
                                             double valueVariance,
                                             double rewardVariance)
  : TestBed(arms)
  , rounds(rounds)
{
    valueDistribution =
      std::normal_distribution<double>(valueMean, sqrt(valueVariance));
    rewardDistribution = std::normal_distribution<double>(0, rewardVariance);
}

TestResult
ConstantRewardTestBed::test(BanditSolver* solver, int numberOfTests)
{
    TestResult result(rounds);

    for (int t = 0; t < numberOfTests; t++) {
        // create problem
        std::vector<double> values(arms);
        for (int arm = 0; arm < arms; arm++)
            values[arm] = valueDistribution(generator);

        int best = 0;
        double maxValue = std::numeric_limits<double>::lowest();
        for (int arm = 0; arm < arms; arm++)
            if (values[arm] > maxValue) {
                maxValue = values[arm];
                best = arm;
            }

        // make solver solve it
        solver->reset();
        for (int round = 0; round < rounds; round++) {
            int choice = solver->getChoice();
            double reward = rewardDistribution(generator) + values[choice];
            solver->setReward(reward);

            if (choice == best)
                result.optimalChoices[round] += 1;
            result.averageReward[round] += reward;

            result.averageEstimate[round] += solver->getAverageEstimate();
        }
    }

    // calculate averages
    for (int round = 0; round < rounds; round++) {
        result.optimalChoices[round] /= numberOfTests;
        result.averageReward[round] /= numberOfTests;
        result.averageEstimate[round] /= numberOfTests;
    }

    return result;
}

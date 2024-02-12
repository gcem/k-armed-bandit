#include "TestResult.hpp"
#include <fstream>

TestResult::TestResult(int rounds)
  : averageReward(rounds, 0)
  , optimalChoices(rounds, 0)
  , averageEstimate(rounds, 0)
{}

void
TestResult::exportTxt(std::string filename)
{
    std::ofstream file(filename);

    for (auto num : optimalChoices)
        file << num << ' ';
    file << '\n';

    for (auto num : averageReward)
        file << num << ' ';
    file << '\n';

    if (averageEstimate.size()) {
        for (auto num : averageEstimate)
            file << num << ' ';
        file << '\n';
    }

    file.close();
}

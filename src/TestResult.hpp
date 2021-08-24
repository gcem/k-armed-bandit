#include <vector>

class TestResult
{
public:
    TestResult(int rounds);

    std::vector<double> optimalChoices;
    std::vector<double> averageReward;
};
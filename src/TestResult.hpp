#pragma once

#include <vector>

class TestResult
{
public:
    /**
     * @brief Initializes all vector elements to 0
     *
     * @param rounds
     */
    TestResult(int rounds);

    std::vector<double> optimalChoices;
    std::vector<double> averageReward;
};
#pragma once

#include <string>
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

    /**
     * @brief Exports data as plain text
     *
     * Array elements are exported on a single line, separated by spaces
     * Lines are ordered with the order in this class
     *
     * @param filename
     */
    void exportTxt(std::string filename);

    // order of fields below are important for export functions

    std::vector<double> optimalChoices;
    std::vector<double> averageReward;

    std::vector<double> averageEstimate;

    // order of fields above are important for export functions
};
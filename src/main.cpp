#include "ChangingRewardTestBed.hpp"
#include "ConstantRewardTestBed.hpp"
#include "ConstantStepSizeEpsilonGreedySolver.hpp"
#include "SampleAverageEpsilonGreedySolver.hpp"
#include <iomanip>
#include <sstream>
#include <string>

int
main()
{
    // this should normally not be set in main ^_^
    int arms = 10;

    ConstantRewardTestBed testBed(arms, 5000, 0, 1, 1);
    // ChangingRewardTestBed testBed(arms, 50000, 0, 0.0001, 1);

    std::vector<double> epsilons{ 0, 0.01, 0.1 };

    // for (double epsilon : epsilons) {
    //     SampleAverageEpsilonGreedySolver solver(arms, epsilon, 0);
    //     auto results = testBed.test(&solver, 1000);

    //     std::ostringstream str;
    //     str << "changing_results_eps_" << std::fixed << std::setprecision(2)
    //         << epsilon << ".txt";

    //     results.exportTxt(str.str());
    // }

    ConstantStepSizeEpsilonGreedySolver solverEpsilon(arms, 0.1, 0, 0.1);
    ConstantStepSizeEpsilonGreedySolver solverGreedy(arms, 0, 5, 0.1);

    auto resultsEpsilon = testBed.test(&solverEpsilon, 20000);
    auto resultsGreedy = testBed.test(&solverGreedy, 20000);

    resultsEpsilon.exportTxt("comparison_epsilon.txt");
    resultsGreedy.exportTxt("comparison_greedy.txt");

    return 0;
}
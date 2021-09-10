#include "ConstantRewardTestBed.hpp"
#include "SampleAverageEpsilonGreedySolver.hpp"

int
main()
{
    // this should normally not be set in main ^_^
    int arms = 10;

    ConstantRewardTestBed testBed(arms, 10000, 0, 1, 1);
    SampleAverageEpsilonGreedySolver solver1(arms, 0.1, 0);
    SampleAverageEpsilonGreedySolver solver2(arms, 0.01, 0);
    SampleAverageEpsilonGreedySolver solver3(arms, 0, 0);

    auto results1 = testBed.test(&solver1, 1000);
    auto results2 = testBed.test(&solver2, 1000);
    auto results3 = testBed.test(&solver3, 1000);
    results1.exportTxt("results_eps_0-1.txt");
    results2.exportTxt("results_eps_0-01.txt");
    results3.exportTxt("results_greedy.txt");

    return 0;
}

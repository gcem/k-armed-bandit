#include "ConstantRewardTestBed.hpp"
#include "SampleAverageEpsilonGreedySolver.hpp"

int
main()
{
    // this should normally not be set in main ^_^
    int arms = 10;

    ConstantRewardTestBed testBed(arms, 1000, 0, 1, 1);
    SampleAverageEpsilonGreedySolver solver(arms, 0.1, 0);

    auto results = testBed.test(&solver, 100);
    results.exportTxt("results_saeg.txt");

    return 0;
}
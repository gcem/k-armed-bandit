#include "ConstantRewardTestBed.hpp"
#include "ChangingRewardTestBed.hpp"
#include "SampleAverageEpsilonGreedySolver.hpp"
#include <string>

int
main()
{
    // this should normally not be set in main ^_^
    int arms = 10;

<<<<<<< Updated upstream
    ConstantRewardTestBed testBed(arms, 3000, 0, 1, 1);
    SampleAverageEpsilonGreedySolver solver(arms, 0.1, 0);

    auto results = testBed.test(&solver, 1000);
    results.exportTxt("results_saeg.txt");
=======
    // ConstantRewardTestBed testBed(arms, 10000, 0, 1, 1);
    ChangingRewardTestBed testBed(arms, 10000, 0, 0.0001, 1);

    std::vector<double> epsilons {0, 0.01, 0.1};

    for (double epsilon : epsilons) {
        SampleAverageEpsilonGreedySolver solver(arms, epsilon, 0);
        auto results3 = testBed.test(&solver3, 1000);
        // TODO
        results1.exportTxt("ch_results_eps_0.10.txt");
    }
>>>>>>> Stashed changes

    return 0;
}
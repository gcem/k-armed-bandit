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

    // ConstantRewardTestBed testBed(arms, 50000, 0, 1, 1);
    ChangingRewardTestBed testBed(arms, 50000, 0, 0.0001, 1);

    std::vector<double> epsilons{ 0, 0.01, 0.1 };

    // for (double epsilon : epsilons) {
    //     SampleAverageEpsilonGreedySolver solver(arms, epsilon, 0);
    //     auto results = testBed.test(&solver, 1000);

    //     std::ostringstream str;
    //     str << "changing_results_eps_" << std::fixed << std::setprecision(2)
    //         << epsilon << ".txt";

    //     results.exportTxt(str.str());
    // }

    std::vector<double> alphas{ 1, 0.5, 0.1, 0.01, 0.001 };

    for (double alpha : alphas) {
        ConstantStepSizeEpsilonGreedySolver solver(arms, 0.1, 0, alpha);
        auto results = testBed.test(&solver, 1000);

        std::ostringstream str;
        str << "const_step_alpha_" << std::fixed << std::setprecision(2)
            << alpha << "_results_eps_0.10.txt";

        results.exportTxt(str.str());
    }

    return 0;
}
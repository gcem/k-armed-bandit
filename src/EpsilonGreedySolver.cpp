#include "EpsilonGreedySolver.hpp"
#include <limits>
#include <random>

EpsilonGreedySolver::EpsilonGreedySolver(int arms,
                                         double epsilon,
                                         double initialEstimates)
  : BanditSolver(arms)
  , epsilon(epsilon)
  , initialEstimates(initialEstimates)
  , valueEstimates(arms, initialEstimates)
{}

int
EpsilonGreedySolver::getChoice()
{
    // make a random choice with probability epsilon
    std::uniform_real_distribution<double> uniformDistribution;
    std::default_random_engine generator;
    if (uniformDistribution(generator) < epsilon) {
        lastChoice = rand() % arms;
        return lastChoice;
    }

    double maxValue = std::numeric_limits<double>::lowest();
    int maxArm = 0, nMax = 0;
    for (int i = 0; i < arms; i++) {
        if (valueEstimates[i] > maxValue) {
            maxValue = valueEstimates[i];
            maxArm = i;
            nMax = 1;
        } else if (valueEstimates[i] == maxValue)
            nMax++;
    }

    if (nMax == 1) {
        lastChoice = maxArm;
        return maxArm;
    } else {
        // choose a random arm among greedy choices
        int choice = rand() % nMax;
        for (int i = 0; i < arms; i++) {
            if (valueEstimates[i] == maxValue)
                choice--;
            if (choice == -1)
                return i;
        }
    }
}

void
EpsilonGreedySolver::reset()
{
    valueEstimates = std::vector<double>(arms, initialEstimates);
}

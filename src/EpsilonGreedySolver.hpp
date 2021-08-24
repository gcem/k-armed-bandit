#include "BanditSolver.hpp"
#include <vector>

/**
 * @brief Tries a random arm with the probability Epsilon
 *
 */
class EpsilonGreedySolver : public BanditSolver
{
public:
    EpsilonGreedySolver(int arms, double epsilon, double initialEstimates);

    int getChoice() override final;

protected:
    int lastChoice;
    double epsilon;
    std::vector<double> valueEstimates;
};
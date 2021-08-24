#include "TestBed.hpp"

class ConstantRewardTestBed : public TestBed
{
public:
    ConstantRewardTestBed(int arms,
                          int rounds,
                          double mean = 0,
                          double variance = 1);

    TestResult test(BanditSolver* solver, int numberOfTests) override;
};
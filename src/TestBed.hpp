#include "BanditSolver.hpp"
#include "TestResult.hpp"

class TestBed
{
public:
    TestBed(int arms);

    virtual TestResult test(BanditSolver* solver) = 0;
};
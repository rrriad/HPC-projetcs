// Problem.h
#pragma once
#include "Equation.h"
#include <memory>

class Problem {
public:
    Problem(std::shared_ptr<IMesh> meshPtr, double advectionVelocity);

    void solve();
    void solveTimeLoop(std::shared_ptr<IMesh> meshPtr);

private:
    std::shared_ptr<IMesh> mesh;
    Equation equation;
};


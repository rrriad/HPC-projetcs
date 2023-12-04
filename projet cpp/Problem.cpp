// Problem.cpp
#include "Problem.h"
#include "variable.h"

Problem::Problem(std::shared_ptr<IMesh> meshPtr, double advectionVelocity) 
    : mesh(meshPtr), equation(meshPtr, advectionVelocity) {}

void Problem::solve() {
    Variable u_n(mesh);
    Variable u_np1(mesh);

    equation.setInitialCondition(u_n);
    equation.setInitialCondition(u_np1);

    for (int n = 1; n < mesh->getNumTimePoints(); ++n) {
        equation.compute(u_n, u_np1);

        // Màj u_n avec u_np1
        for (int i = 0; i < mesh->getNumSpacePoints(); ++i) {
            u_n[i] = u_np1[i];
        }
    }
}

void Problem::solveTimeLoop(std::shared_ptr<IMesh> meshPtr) {
    equation.computeTimeLoop(meshPtr);
}





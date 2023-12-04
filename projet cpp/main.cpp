// main.cpp
#include <memory>
#include "IMesh.h"
#include "UniformMesh.h"
#include "Equation.h"
#include "LaxWendroff.h"

int main() {
    // instance de uniformmesh, definir les parametres
    std::shared_ptr<IMesh> myMesh = std::make_shared<UniformMesh>(0, 2, 1, 0, 50, 0.5);

    // instance de Equation 
    Equation myEquation(myMesh, 1.0);

    // conditions initial
    Variable u_n(myMesh);
    myEquation.setInitialCondition(u_n);

    
    myEquation.computeTimeLoop(myMesh);

    return 0;
}


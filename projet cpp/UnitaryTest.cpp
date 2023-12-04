#include <gtest/gtest.h>
#include "UniformMesh.h"
#include "Problem.h"
#include "Equation.h"
#include "variable.h"
#include <cmath>
TEST(UnitaryTest, EquationTest) {
    
    UniformMesh tempMesh(0, 1, 0.5, 0, 5, 2);

    
    std::shared_ptr<IMesh> meshPtr = std::make_shared<UniformMesh>(tempMesh);

    
    Variable variable(meshPtr);

   
    Equation equation(meshPtr, 1.0);

    
    equation.setInitialCondition(variable);
    
    for (int i = 0; i < variable.size(); ++i) {
        ASSERT_EQ(variable[i], std::exp(-std::pow((tempMesh.x_i(i) - 2.5) / (10.0 * tempMesh.getSpaceStep()), 2.0) / 2.0));
    }

    
    Variable u_n(meshPtr);
    Variable u_np1(meshPtr);
   
    for (int i = 0; i < u_n.size(); ++i) {
        u_n[i] = 1.0;
    }

    equation.compute(u_n, u_np1);
  
    for (int i = 1; i < meshPtr->getNumSpacePoints(); ++i) {
        double expected_value = 1.0 - 1.0 * (u_n[i] - u_n[i - 1]) / tempMesh.getSpaceStep();
        ASSERT_DOUBLE_EQ(u_np1[i], expected_value);
    }
}


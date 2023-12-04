#pragma once
#include "IMesh.h"
#include "variable.h"

class Upwind {
public:
    template <typename MeshType>
    static void update(double advectionVelocity, const MeshType& mesh, const Variable& u_n, Variable& u_np1);
};


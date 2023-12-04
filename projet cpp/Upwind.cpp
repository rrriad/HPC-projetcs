
#include "Upwind.h"
#include "IMesh.h"
#include "variable.h"

template <typename MeshType>
void Upwind::update(double advectionVelocity, const MeshType& mesh, const Variable& u_n, Variable& u_np1) {
    double CFL = advectionVelocity * mesh.getTimeStep() / mesh.getSpaceStep();

    for (int i = 1; i < mesh.getNumSpacePoints(); ++i) {
        u_np1[i] = u_n[i] - CFL * (u_n[i] - u_n[i - 1]);
    }

    u_np1[0] = u_n[0] - CFL * (u_n[0] - u_n[mesh.getNumSpacePoints() - 1]);
}


template void Upwind::update<IMesh>(double advectionVelocity, const IMesh& mesh, const Variable& u_n, Variable& u_np1);


#include "LaxWendroff.h"
#include <cmath>

template<typename Mesh>
void LaxWendroff::update(double advectionVelocity, const Mesh& mesh, const Variable& u_n, Variable& u_np1) {
    double dt = mesh.getTimeStep();
    double dx = mesh.getSpaceStep();
    double a = advectionVelocity;

    for (int i = 1; i < mesh.getNumSpacePoints() - 1; ++i) {
        u_np1[i] = u_n[i] - a * dt / (2.0 * dx) * (u_n[i + 1] - u_n[i - 1])
            + std::pow(a * dt / dx, 2) / 2.0 * (u_n[i + 1] - 2.0 * u_n[i] + u_n[i - 1]);
    }

    // conditions de bords
    u_np1[0] = u_n[0] - a * dt / (2.0 * dx) * (u_n[1] - u_n[mesh.getNumSpacePoints() - 1])
        + std::pow(a * dt / dx, 2) / 2.0 * (u_n[1] - 2.0 * u_n[0] + u_n[mesh.getNumSpacePoints() - 1]);

    u_np1[mesh.getNumSpacePoints() - 1] = u_n[mesh.getNumSpacePoints() - 1]
        - a * dt / (2.0 * dx) * (u_n[0] - u_n[mesh.getNumSpacePoints() - 2])
        + std::pow(a * dt / dx, 2) / 2.0 * (u_n[0] - 2.0 * u_n[mesh.getNumSpacePoints() - 1] + u_n[mesh.getNumSpacePoints() - 2]);
}


#pragma once
#include "IMesh.h"

class UniformMesh : public IMesh {
public:
    UniformMesh(double t_ini, double t_final, double dt, double x_min, double x_max, double dx);
    ~UniformMesh() override;

    double getInitialTime() const override;
    double getFinalTime() const override;
    double getTimeStep() const override;

    double getInitialPosition() const override;
    double getFinalPosition() const override;
    double getSpaceStep() const override;
    double getPosition(int index) const override;

    
    double x_size() const override;

    
    int getNumTimePoints() const override;
    int getNumSpacePoints() const override;
    double x_i(int i) const override;

private:
    double initialTime;
    double finalTime;
    double timeStep;

    double initialPosition;
    double finalPosition;
    double spaceStep;
};


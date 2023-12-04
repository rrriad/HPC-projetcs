#pragma once

#include <vector>

class IMesh {
public:
    virtual ~IMesh() {}

    virtual double getInitialTime() const = 0;
    virtual double getFinalTime() const = 0;
    virtual double getTimeStep() const = 0;

    virtual double getInitialPosition() const = 0;
    virtual double getFinalPosition() const = 0;
    virtual double getSpaceStep() const = 0;

    virtual int getNumTimePoints() const = 0;
    virtual int getNumSpacePoints() const = 0;
    virtual double getPosition(int index) const = 0;

    virtual double x_size() const = 0;
    virtual double x_i(int i) const = 0; // Nouvelle méthode ajoutée
};


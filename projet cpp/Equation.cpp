#include "Equation.h"
#include "Upwind.h"
#include <cmath>
#include <iostream>
#include <iomanip>
#include "LaxWendroff.h"

// définition de la classe Equation
template <typename Scheme>
void Equation::compute_for_scheme(double t, const std::shared_ptr<IMesh>& meshPtr, Variable& u_n, Variable& u_np1) {
    // Appel de la fonction statique update du schéma numérique spécifié
    Scheme::update(advectionVelocity, *meshPtr, u_n, u_np1);
}

//constructeur de la classe Equation avec un maillage et la vitesse d'advection
Equation::Equation(std::shared_ptr<IMesh> meshPtr, double advectionVelocity)
    : mesh(meshPtr), advectionVelocity(advectionVelocity) {}


Equation::Equation() : mesh(nullptr), advectionVelocity(0.0) {} //constructeur par defaut de la classe Equation


Equation::~Equation() {} //destructeur de la classe Equation

//fonction pour définir la condition initiale des variable
void Equation::setInitialCondition(Variable& variable) {
    compute_initial_condition(variable); //initialisation de la condition initiale 
}

// Fonction de calcul de la solution pour le schéma Upwind
void Equation::compute(Variable& u_n, Variable& u_np1) {
    double CFL = advectionVelocity * mesh->getTimeStep() / mesh->getSpaceStep(); //calcul du nombre de CFL (Courant-Friedrichs-Lewy)
    Upwind::update(advectionVelocity, *mesh, u_n, u_np1); // màj de la solution avec le schema Upwind
}

// Fonction de calcul de la condition initiale (gaussienne)
void Equation::compute_initial_condition(Variable& variable) {
    double mu = (mesh->getFinalPosition() - mesh->getInitialPosition()) / 2.0;
    double sigma = 10.0 * mesh->getSpaceStep();

    // Boucle pour calculer la gaussienne sur le maillage
    for (int i = 0; i < mesh->getNumSpacePoints(); ++i) {
        double x = mesh->getPosition(i);
        // Gaussienne avec t=0, condition initiale
        variable[i] = std::exp(-(x - mu) * (x - mu) / (2.0 * sigma * sigma));
    }
}

// Fonction de calcul de la solution exacte basée sur une gaussienne
void Equation::compute_exact_solution(const std::shared_ptr<IMesh>& meshPtr, Variable& u_ref, double t) {
    double mu = (meshPtr->getFinalPosition() + meshPtr->getInitialPosition()) / 2.0;
    double sigma = 10.0 * meshPtr->getSpaceStep();

    // Boucle pour calculer la distribution gaussienne sur le maillage
    for (int i = 0; i < meshPtr->getNumSpacePoints(); ++i) {
        double x = meshPtr->getPosition(i);
        // Gaussienne pour calculer la solution exacte
        u_ref[i] = std::exp(-(x - advectionVelocity * t - mu) * (x - advectionVelocity * t - mu) / (2.0 * sigma * sigma));
    }
}

// Fonction principale pour effectuer la boucle temporelle
void Equation::computeTimeLoop(std::shared_ptr<IMesh> meshPtr) {
    Variable u_n_upwind(meshPtr);
    Variable u_np1_upwind(meshPtr);

    Variable u_n_laxwendroff(meshPtr);
    Variable u_np1_laxwendroff(meshPtr);

    Variable u_ref(meshPtr);

    // Initialisation des conditions initiales pour les deux schémas
    setInitialCondition(u_n_upwind);
    setInitialCondition(u_n_laxwendroff);

    // Calcul du CFL
    double CFL = advectionVelocity * meshPtr->getTimeStep() / meshPtr->getSpaceStep();
    std::cout << "--- Résolution du problème ---" << std::endl;

    // Boucle temporelle
    for (double t = 0.0; t <= meshPtr->getFinalTime(); t += meshPtr->getTimeStep()) {
        
        std::cout << "--- Calcul de l'équation au temps : " << t << " ---" << std::endl;

        // Schéma Upwind
        Upwind::update(advectionVelocity, *meshPtr, u_n_upwind, u_np1_upwind);
        u_n_upwind = u_np1_upwind;

        // Schéma Lax-Wendroff
        LaxWendroff::update(advectionVelocity, *meshPtr, u_n_laxwendroff, u_np1_laxwendroff);
        u_n_laxwendroff = u_np1_laxwendroff;

        // Calcul de la solution exacte
        compute_exact_solution(meshPtr, u_ref, t);

        // Affichage à partir d'un certain temps
        if (std::abs(t - 2.0) < 1e-10) 
        {
            std::cout << std::setw(3) << "i" << std::setw(15) << "x_i" << std::setw(15) << "u_upwind" << std::setw(15) << "u_laxwendroff" << std::setw(15) << "u_exact" << std::endl;
            for (int i = 0; i < meshPtr->getNumSpacePoints(); ++i) {
                std::cout << std::setw(3) << i << std::setw(15) << meshPtr->getPosition(i)
                          << std::setw(15) << u_n_upwind[i] << std::setw(15) << u_n_laxwendroff[i]
                          << std::setw(15) << u_ref[i] << std::endl;
            }
        }
    }
}


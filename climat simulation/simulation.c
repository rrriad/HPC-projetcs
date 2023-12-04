#include <math.h>
#include <stdio.h>

#define real double

// Solar constant W / m ^ 2
#define S0 1370

// Stefan - Boltzmann constant W / m2 / K4
#define SIGMA 0.00000005670367

// Temperature inertia (in years)
#define THETA 2100.0

// Albedo, in this simulation albedo is considered constant
// in reality albedo can become lower with increased temperatures
// due to ice cap melting
#define ALBEDO 0.33

// Initial values

// Simulation starts in 2007
static const real t0 = 2007.0;
// Temperaturature in 2007 in K
static const real T0 = 288.45;
// CO2 concentration in 2007 in ppm
static real CO2 = 370.0;

// Annual rate of change in CO2 concentration for different scenarios
//static const real CO2AnnualChange = 2.0;  // Example: 2 ppm per year for RCP 8.0
static const real CO2AnnualChange = 0.01;  // Example: 1.5 ppm per year for RCP 6.5

static real G(real T, real co2)
{
    return 3.35071874e-03 * T + 3.20986702e-05 * co2 - 0.561593690144655;
}

real P_in(real t)
{
    return S0 * (1.0 - ALBEDO) * (1.0 + 0.5 * cos(2 * M_PI * (t - t0) / 365.0));
}

real P_out(real t, real T)
{
    return SIGMA * pow(T, 4) * (1.0 - G(T, CO2));
}

real F(real t, real T)
{
    CO2 += CO2AnnualChange;
    return (P_in(t) - P_out(t, T)) / THETA;
}

real euler(real t_final, int steps)
{
    real T = T0;
    real t = t0;
    real dt = (t_final - t0) / steps;

    for (int step = 0; step < steps; step++)
    {
        real dT = F(t, T);
        T += dt * dT;
        t += dt;
    }
    return T;
}

int main(int argc, char **argv)
{
    real totalTime = 100.0;
    int numSteps = totalTime * 365.0;

    FILE *datafile = fopen("temperature_data.txt", "w");

    fprintf(datafile, "Year Temperature en K CO2 Concentration ppm\n");

    for (int year = 2007; year <= 2107; year++)
    {
        real Tn = euler(year, 365);
        fprintf(datafile, "%d %lf %lf\n", year, Tn, CO2);
        printf("Year: %d, Temperature: %lf K, CO2 Concentration: %lf ppm\n", year, Tn, CO2);
    }

    fclose(datafile);

    return 0;
}


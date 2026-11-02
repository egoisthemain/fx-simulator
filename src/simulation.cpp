#include "simulation.h"

#include <cmath>

double simulate_final_rate(
    double initial_rate,
    double annual_drift,
    double annual_volatility,
    int days,
    std::mt19937& generator,
    std::normal_distribution<double>& normal
) {
    const double dt = 1.0 / 252.0;
    double rate = initial_rate;

    for (int day = 1; day <= days; ++day) {
        const double shock = normal(generator);
        rate *= std::exp(
        (annual_drift - 0.5 * annual_volatility * annual_volatility) * dt
        + annual_volatility * std::sqrt(dt) * shock);
    }

    return rate;
}
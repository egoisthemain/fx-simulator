#pragma once

#include <random>

/**
 * @brief Simulates the final exchange rate using geometric Brownian motion.
 *
 * @param initial_rate Initial exchange rate.
 * @param annual_drift Annual drift parameter.
 * @param annual_volatility Annual volatility.
 * @param days Number of trading days; one year contains 252 trading days.
 * @param generator Random number generator, modified during simulation.
 * @param normal Standard normal distribution, modified during simulation.
 * @return Exchange rate after the specified number of trading days.
 */

double simulate_final_rate(
    double initial_rate,
    double annual_drift,
    double annual_volatility,
    int days,
    std::mt19937& generator,
    std::normal_distribution<double>& normal
);
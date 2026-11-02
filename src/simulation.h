#pragma once

#include <random>

double simulate_final_rate(
    double initial_rate,
    double annual_drift,
    double annual_volatility,
    int days,
    std::mt19937& generator,
    std::normal_distribution<double>& normal
);
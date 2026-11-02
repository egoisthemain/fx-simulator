#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include <cmath>

#include "simulation.h"

TEST_CASE("Zero days preserve the initial rate") {
    std::mt19937 generator(42);
    std::normal_distribution<double> normal(0.0, 1.0);

    const double result = simulate_final_rate(
        90.0, 0.05, 0.20, 0, generator, normal
    );

    CHECK(result == doctest::Approx(90.0));
}

TEST_CASE("Zero volatility on few days") {
    std::mt19937 generator(42);
    std::normal_distribution<double> normal(0.0, 1.0);
    const int days = 10;
    const double initial_rate = 90.0;
    double annual_drift = 0.05;

    const double result = simulate_final_rate(
        initial_rate, annual_drift, 0.0, days, generator, normal
    );

    double expected_res = 
        initial_rate * std::exp(annual_drift * days/252.0);

    CHECK(result == doctest::Approx(expected_res));
}
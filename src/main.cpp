#include <cmath>
#include <iostream>
#include <random>
#include "simulation.h"

int main() {
    const double initial_rate = 90.0;
    const double annual_drift = 0.05;
    const double annual_volatility = 0.20;

    const int days = 60;

    std::mt19937 generator(42);
    std::normal_distribution<double> normal(0.0, 1.0);

    const int simulations = 1000;
    double sum_final_rates = 0.0;
    int growth_count = 0;

    for (int simulation = 0; simulation < simulations; ++simulation) {
        const double rate = simulate_final_rate(
            initial_rate, annual_drift,
            annual_volatility, days,
            generator, normal
        );
        sum_final_rates += rate;

        if (rate > initial_rate) {
            ++growth_count;
        }
    
    }

    const double mean_final_rate = sum_final_rates / simulations;
    const double growth_percent = 100.0 * growth_count / simulations;

    std::cout << "Simulations: " << simulations << '\n';
    std::cout << "Mean final rate: " << mean_final_rate << '\n';

    std::cout << "Growth scenarios: " << growth_count << '\n';
    std::cout << "Growth percentage: " << growth_percent << "%\n";

}

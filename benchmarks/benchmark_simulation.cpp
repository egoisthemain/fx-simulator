#include "simulation.h"

#include <chrono>
#include <iostream>
#include <random>

int main() {
    const int simulations = 10000;
    const int days = 252;

    std::mt19937 generator(42);
    std::normal_distribution<double> normal(0.0, 1.0);

    double sum = 0.0;

    const auto start = std::chrono::steady_clock::now();

    for (int i = 0; i < simulations; i++) {
        sum += simulate_final_rate(
            90.0, 0.05, 0.20, days, generator, normal
        );
    }

    const auto finish = std::chrono::steady_clock::now();

    const double elapsed_ms = 
        std::chrono::duration<double, std::milli>(
                finish - start).count();

    std::cout << "Simulations: " << simulations << '\n';
    std::cout << "Days per simulation: " << days << '\n';
    std::cout << "Total time: " << elapsed_ms << "ms\n";
    std::cout << "Time per simulation: " << elapsed_ms / simulations << "ms\n";
    std::cout << "Mean final rate: " << sum / simulations << '\n';
}
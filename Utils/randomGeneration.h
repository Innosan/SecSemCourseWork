//
// Created by CosmoPC on 05.04.2024.
//

#pragma once

#include <vector>
#include <random>

#include <cmath>

std::vector<std::vector<double>> generateRandomMatrix(double minValue, double maxValue) {
    std::random_device rd; // Seed for random number generation
    std::mt19937 gen(rd());  // Mersenne Twister random number engine
    std::uniform_real_distribution dis(minValue, maxValue); // Distribution for random values

    int n = getNumber("Input N (rows):", 1, 300);
    int m = getNumber("Input M (columns):", 1, 300);

    std::vector<std::vector<double>> matrix(n, std::vector<double>(m));

    // Fill the matrix with random values
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            double value = dis(gen);
            // Round the value to 2 decimal places
            value = std::round(value * 100) / 100;
            matrix[i][j] = value;
        }
    }

    return matrix;
}

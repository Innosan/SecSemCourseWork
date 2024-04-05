//
// Created by CosmoPC on 05.04.2024.
//

#pragma once

#include <vector>
#include <random>

template <typename T>
std::vector<std::vector<T>> generateRandomMatrix(int n, int m, double minValue, double maxValue) {
    std::random_device rd; // Seed for random number generation
    std::mt19937 gen(rd());  // Mersenne Twister random number engine
    std::uniform_real_distribution dis(minValue, maxValue); // Distribution for random values

    std::vector<std::vector<T>> matrix(n, std::vector<T>(m));

    // Fill the matrix with random values
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            matrix[i][j] = dis(gen);
        }
    }

    return matrix;
}

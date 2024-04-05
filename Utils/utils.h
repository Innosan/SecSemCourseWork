//
// Created by CosmoPC on 03.04.2024.
//

#ifndef SECSEMCOURSEWORK_UTILS_H
#define SECSEMCOURSEWORK_UTILS_H

#include <iostream>
#include <vector>

template <typename T>
void printVector(const std::vector<T>& array, const std::string& message);

template <typename T>
void printMatrix(std::vector<std::vector<T>> matrix, const std::string& message) {
    std::cout << message << std::endl;

    for (auto row : matrix) {
        for (T elem : row) {
            std::cout << elem << "\t";
        }

        std::cout << std::endl;
    }
};

#endif //SECSEMCOURSEWORK_UTILS_H

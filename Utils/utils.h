//
// Created by CosmoPC on 03.04.2024.
//

#ifndef SECSEMCOURSEWORK_UTILS_H
#define SECSEMCOURSEWORK_UTILS_H

#include <iostream>
#include <vector>
#include <random>
#include <string>
#include <iomanip>

template <typename T>
void printVector(const std::vector<T>& array, const std::string& message) {
    std::cout << std::endl << message << std::endl;

    for (T elem : array) {
        if (elem == static_cast<int>(elem)) {
            std::cout << static_cast<int>(elem) << " ";
        } else {
            std::cout << std::fixed << std::setprecision(5) << elem << " ";
        }
    }

    std::cout << std::endl;
};

/**
 * Slice a number into its digits
 *
 * @param num - the number to be sliced
 * @return a vector of digits
 */
std::pair<std::vector<int>, int> splitIntoDigits(double num);

/**
 * Convert a vector of digits into a number
 *
 * @param digits - the vector of digits
 * @return the number
 */
double convertToNumber(const std::pair<std::vector<int>, int>& digitsAndDotPosition);

template <typename T>
void printMatrix(std::vector<std::vector<T>> matrix, const std::string& message) {
    std::cout << message << std::endl;

    for (auto row : matrix) {
        for (T elem : row) {
            if (elem == static_cast<int>(elem)) {
                std::cout << static_cast<int>(elem) << "\t";
            } else {
                std::cout << std::fixed << std::setprecision(5) << elem << "\t";
            }
        }

        std::cout << std::endl;
    }
};

#endif //SECSEMCOURSEWORK_UTILS_H

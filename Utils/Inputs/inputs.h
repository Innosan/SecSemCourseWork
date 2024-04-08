//
// Created by CosmoPC on 04.04.2024.
//

#ifndef SECSEMCOURSEWORK_INPUTS_H
#define SECSEMCOURSEWORK_INPUTS_H

#include <iostream>
#include <vector>
#include <limits>

/**
 * \brief Get int user int input.
 *
 * \param welcomeMessage - message to display to the user
 * \param min - minimum value
 * \param max - maximum value
 *
 * \return int user input
 */
int getIntUserInput(const std::string& welcomeMessage, int min = 0, int max = INT_MAX);

/**
 * \brief Get string user input.
 *
 * \param welcomeMessage - message to display to the user
 *
 * \return string user input
 */
std::string getStringUserInput(const std::string& welcomeMessage);

/**
 * \brief Get matrix user input.
 *
 * \param welcomeMessage - message to display to the user
 * \param rows - number of rows
 * \param cols - number of columns
 *
 * \return matrix user input
 */
std::vector<std::vector<int>> getMatrixUserInput(const std::string& welcomeMessage, int rows, int cols);

/**
 * Get confirmation for user action
 *
 * @param welcomeMessage - message to display to the user
 * @return action confirmation
 */
bool getBoolConfirmation(const std::string& welcomeMessage);

template <typename T>
T getNumber(const std::string& welcomeMessage, T min = std::numeric_limits<T>::lowest(), T max = std::numeric_limits<T>::max()) {
    T input;

    std::cout << welcomeMessage << std::endl;

    while (true) {
        std::cin >> input;

        if (std::cin.fail() || input < min || input > max) {
            std::cout << "Invalid input. Please enter a number from " << min << " to " << max << std::endl;

            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break;
        }
    }

    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    return input;
}

template <typename T>
std::vector<std::vector<T>> getMatrixUserInput(const std::string& welcomeMessage) {
    std::vector<std::vector<T>> matrix;

    int n = getIntUserInput("Input N (rows):", 1, 300);
    int m = getIntUserInput("Input M (columns):", 1, 300);

    std::cout << welcomeMessage << std::endl;
    for (int i = 0; i < n; i++) {
        std::vector<T> row;

        for (int j = 0; j < m; j++) {
            T input = getNumber<T>("Enter element " + std::to_string(i + 1) + ", " + std::to_string(j + 1) + ": ");
            row.push_back(input);
        }

        matrix.push_back(row);
    }

    return matrix;
}

#endif //SECSEMCOURSEWORK_INPUTS_H

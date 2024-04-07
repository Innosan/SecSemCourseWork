//
// Created by CosmoPC on 04.04.2024.
//
#include <iostream>
#include <string>
#include "inputs.h"

int getIntUserInput(const std::string& welcomeMessage, int min, int max) {
    int input = 0;

    std::cout << welcomeMessage << std::endl;

    do {
        std::cin >> input;

        if (std::cin.fail() || input <= min || input >= max) {
            std::cout << "Invalid input. Please enter a number from " << min + 1 << " to " << max - 1 << std::endl;

            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
        }
    } while (std::cin.fail() || input <= min || input >= max);

    std::cin.clear();
    std::cin.ignore(INT_MAX, '\n');

    return input;
}

std::string getStringUserInput(const std::string& welcomeMessage) {
    std::string input;
    std::cout << welcomeMessage << std::endl;

    std::getline(std::cin, input);

    return input;
}

std::vector<std::vector<int>> getMatrixUserInput(const std::string& welcomeMessage, int rows, int cols) {
    std::vector<std::vector<int>> matrix;

    std::cout << welcomeMessage << std::endl;

    for (int i = 0; i < rows; i++) {
        std::vector<int> row;

        for (int j = 0; j < cols; j++) {
            int input = getIntUserInput("Enter element " + std::to_string(i + 1) + ", " + std::to_string(j + 1) + ": ", INT_MIN, INT_MAX);
            row.push_back(input);
        }

        matrix.push_back(row);
    }

    return matrix;
}

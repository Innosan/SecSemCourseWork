//
// Created by CosmoPC on 04.04.2024.
//

#include <iostream>
#include <memory>
#include <vector>
#include <random>

#include "Menu.h"
#include "../Utils/Inputs/inputs.h"
#include "../Utils/randomGeneration.h"
#include "../Utils/utils.h"

void Menu::display() {
    std::cout << "\n";

    for (MenuOption item : this->options) {
        item.print();
    }
}

void Menu::choose(int index) {
    this->options[index - 1].callAction();
}

void Menu::printWelcomeMessage() {
    std::cout << "Fomin Mikhail Vital\'evich, group 4307, number 25" << std::endl;
    std::cout << "Test 3, task 7." << std::endl;

    std::cout << "For two given texts, find the longest common substring." << std::endl << std::endl;
    std::cout << "The program should output the position at which the text begins in each file, " << std::endl;
    std::cout << "the length of the line and the text of the line itself." << std::endl;
    std::cout << "Provide necessary checks of source data." << std::endl;
};


void Menu::initializeMenu() {
    std::vector<MenuOption> items = {
            // Add mammal
            MenuOption(Menu::LINE_BY_LINE, "Input matrix line by line",  []() {
                // TODO: Implement
            }),

            MenuOption(Menu::FROM_FILE, "Import matrix from file",  []() {
                // TODO: Implement
            }),

            // Read from file
            MenuOption(Menu::RANDOM, "Generate random matrix",  []() {
                int n = getIntUserInput("Input N (rows):", 1, 300);
                int m = getIntUserInput("Input M (columns):", 1, 300);

                auto matrix = generateRandomMatrix<int>(n, m, 1., 100.);
                printMatrix(matrix, "Unsorted matrix");
            }),

            // Exit
            MenuOption(Menu::EXIT, "Exit",  []() { exit(EXIT_SUCCESS); })
    };

    this->options = items;
};

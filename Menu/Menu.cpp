//
// Created by CosmoPC on 04.04.2024.
//

#include <iostream>
#include <memory>
#include <vector>

#include "Menu.h"

#include "../Utils/Inputs/inputs.h"
#include "../Utils/randomGeneration.h"
#include "../Utils/utils.h"

#include "../Sort/runSorts.h"

#include "../Utils/Files/validation.h"
#include "../Utils/Files/files.h"
#include "../Sort/ArraySorter.h"
#include "../Tests/runMainTests.h"

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
    std::cout << "Course work." << std::endl;

    std::cout << "You need to create a console program to sort an array of data" << std::endl;
    std::cout << "by methods: bubble, selection, insertion, Shell and quick sorting." << std::endl;
    std::cout << "Order the digits in each value of the numbers in the matrix in ascending order, " << std::endl;
    std::cout << "then order the data in the columns in descending order." << std::endl;

    std::cout << "Print on the screen unordered (once) and ordered (for each of the methods) data arrays." << std::endl;
    std::cout << "Make a comparative table of the effectiveness of the methods, in which the number of comparisons and overrides" << std::endl;
    std::cout << "in which you should indicate the number of comparisons and permutations of variables in each sorting method in each sorting method." << std::endl;
};

void Menu::initializeMenu() {
    std::vector<MenuOption> items = {
        MenuOption(Menu::LINE_BY_LINE, "Input matrix line by line",  []() {
            auto matrix = getMatrixUserInput<double>("Input matrix elements: ");
            ArraySorter& arraySorter = ArraySorter::getInstance();

            arraySorter.setMatrix(matrix);
            arraySorter.printMainMatrix();

            runSorts(matrix);
            std::cout << "Sorted matrix:" << std::endl;
            printMatrix(matrix, "Sorted matrix: ");

            std::cout << std::endl << std::endl << "Main matrix:" << std::endl;

            arraySorter.printMainMatrix();

            auto isExport = getBoolConfirmation("Do you want to export the results to a file? (1/0): ");
            if (isExport) {
                arraySorter.getResultsHolder().exportCombinedResults();
            }

            arraySorter.getResultsHolder().clearResults();
        }),

        MenuOption(Menu::FROM_FILE, "Import matrix from file",  []() {
            std::string filePath;
            while (true) {
                filePath = getValidFilePath();
                if (fileExists(filePath)) {
                    break;
                }
                std::cout << "File does not exist. Please enter a new path." << std::endl;
            }

            auto matrix = getMatrixFromFile<double>(filePath);

            ArraySorter& arraySorter = ArraySorter::getInstance();

            arraySorter.setMatrix(matrix);
            arraySorter.printMainMatrix();

            runSorts(matrix);
            std::cout << "Sorted matrix:" << std::endl;
            printMatrix(matrix, "Sorted matrix: ");

            std::cout << std::endl << std::endl << "Main matrix:" << std::endl;

            arraySorter.printMainMatrix();

            auto isExport = getBoolConfirmation("Do you want to export the results to a file? (1/0): ");
            if (isExport) {
                arraySorter.getResultsHolder().exportCombinedResults();
            }

            arraySorter.getResultsHolder().clearResults();
        }),

        MenuOption(Menu::RANDOM, "Generate random matrix",  []() {
            ArraySorter& arraySorter = ArraySorter::getInstance();

            auto matrix = generateRandomMatrix(1, 100);

            arraySorter.setMatrix(matrix);
            arraySorter.printMainMatrix();

            runSorts(matrix);
            std::cout << "Sorted matrix:" << std::endl;
            printMatrix(matrix, "Sorted matrix: ");

            std::cout << std::endl << std::endl << "Main matrix:" << std::endl;

            arraySorter.printMainMatrix();

            auto isExport = getBoolConfirmation("Do you want to export the results to a file? (1/0): ");
            if (isExport) {
                arraySorter.getResultsHolder().exportCombinedResults();
            }

            arraySorter.getResultsHolder().clearResults();
        }),

        MenuOption(Menu::RUN_TESTS, "Run tests",  []() {
            runMainTests();
        }),

        MenuOption(Menu::EXIT, "Exit",  []() { exit(EXIT_SUCCESS); })
    };

    this->options = items;
};

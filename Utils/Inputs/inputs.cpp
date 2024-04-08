//
// Created by CosmoPC on 04.04.2024.
//
#include <iostream>
#include <string>
#include "inputs.h"

std::string getStringUserInput(const std::string& welcomeMessage) {
    std::string input;
    std::cout << welcomeMessage << std::endl;

    std::getline(std::cin, input);

    return input;
}

bool getBoolConfirmation(const std::string& welcomeMessage) {
    std::cout << welcomeMessage << std::endl;

    int userInput = getNumber("", -1, 2);
    return userInput == 1;
}

//
// Created by CosmoPC on 04.04.2024.
//

#include <string>
#include <iostream>
#include "files.h"
#include "validation.h"

bool confirmOverwrite(const std::string& filename) {
    std::cout << "File '" << filename << "' already exists." << std::endl;
    std::cout << "Do you want to overwrite it? (y/n): ";

    char answer;
    std::cin >> answer;

    return std::tolower(answer) == 'y';
}

std::string getOverwriteConfirmation(const std::string& fullPath) {
    while (fileExists(fullPath)) {
        if (confirmOverwrite(fullPath)) {
            return fullPath;
        }
        else {
            std::cout << "Please choose another file." << std::endl;
            return getValidFilePath();
        }
    }
    return fullPath;
}
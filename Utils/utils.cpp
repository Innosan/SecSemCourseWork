//
// Created by CosmoPC on 03.04.2024.
//

#include "utils.h"
void printVector(const std::vector<int>& array, const std::string& message) {
    std::cout << message << std::endl;

    for (int i : array) {
        std::cout << i << " ";
    }

    std::cout << std::endl;
}

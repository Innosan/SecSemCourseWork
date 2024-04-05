//
// Created by CosmoPC on 03.04.2024.
//

#include "utils.h"

template <typename T>
void printVector(const std::vector<T>& array, const std::string& message) {
    std::cout << message << std::endl;

    for (int i : array) {
        std::cout << i << " ";
    }

    std::cout << std::endl;
}

//
// Created by CosmoPC on 07.04.2024.
//

#include "tables.h"

void printTable(const std::vector<std::vector<std::string>>& table) {
    int cellWidth = 25; // adjust as needed

    for (const auto& row : table) {
        for (const auto& cell : row) {
            std::cout << std::setw(cellWidth) << std::left << cell;
        }
        std::cout << '\n';
    }
}

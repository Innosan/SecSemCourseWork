//
// Created by CosmoPC on 04.04.2024.
//

#ifndef SECSEMCOURSEWORK_FILES_H
#define SECSEMCOURSEWORK_FILES_H

#include <string>
#include <vector>
#include <fstream>
#include <sstream>

/**
 * Reads data from a file and constructs a matrix vector.
 *
 * \param fileName The name of the file to read.
 * \return A vector of File objects, or an empty vector if there was an error.
 */
template <typename T>
std::vector<std::vector<T>> getMatrixFromFile(const std::string& fileName) {
    std::vector<std::vector<T>> matrix;

    std::ifstream inputFile(fileName);
    if (!inputFile.is_open()) {
        std::cerr << "Error opening file: " << fileName << std::endl;
        return matrix; // Return empty matrix on error
    }

    std::string line;
    while (getline(inputFile, line)) {
        // Handle empty lines or lines with incorrect formatting
        if (line.empty()) {
            std::cerr << "Warning: Skipped empty line." << std::endl;
            continue;
        }

        std::stringstream ss(line);
        std::string token;
        std::vector<T> row;

        // Extract data from the line, handling both int and double values
        while (getline(ss, token, ',')) {
            try {
                if constexpr (std::is_same_v<T, int>) {
                    row.push_back(std::stoi(token));
                } else if constexpr (std::is_same_v<T, double>) {
                    row.push_back(std::stod(token));
                } else {
                    std::cerr << "Unsupported matrix element type." << std::endl;
                    return matrix; // Return empty matrix on error
                }
            } catch (const std::exception& e) {
                std::cerr << "Warning: Parsing field: " << e.what() << std::endl;
                // You can choose to skip the line, continue without the value, or throw an exception
            }
        }

        // Add the row to the matrix
        matrix.push_back(row);
    }

    inputFile.close();
    return matrix;
}

#endif //SECSEMCOURSEWORK_FILES_H

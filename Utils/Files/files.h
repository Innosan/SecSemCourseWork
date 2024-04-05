//
// Created by CosmoPC on 04.04.2024.
//

#ifndef SECSEMCOURSEWORK_FILES_H
#define SECSEMCOURSEWORK_FILES_H

#include <string>
#include <vector>

/**
 * Reads data from a file and constructs a matrix vector.
 *
 * \param fileName The name of the file to read.
 * \return A vector of File objects, or an empty vector if there was an error.
 */
template <typename T>
std::vector<T> getMatrixFromFile(const std::string& fileName);

#endif //SECSEMCOURSEWORK_FILES_H

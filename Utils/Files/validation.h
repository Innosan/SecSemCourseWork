//
// Created by CosmoPC on 04.04.2024.
//

#ifndef SECSEMCOURSEWORK_VALIDATION_H
#define SECSEMCOURSEWORK_VALIDATION_H

#include <iostream>

/**
 * \brief Check if a file exists.
 *
 * \param filename - name of the file to check
 *
 * \return true if the file exists, false otherwise
 */
bool fileExists(const std::string& filename);

/**
 * \brief Check if a file path is valid.
 *
 * \param filePath - path to check
 *
 * \return true if the file path is valid, false otherwise
 */
bool isFilePathValid(const std::string& filePath);

/**
 * \brief Check if a file name is valid (general case and reserved Windows names).
 *
 * \param fileName - name to check
 *
 * \return true if the file name is valid, false otherwise
 */
bool isFileNameValid(const std::string& fileName);

/**
 * \brief Get a valid file path from the user.
 *
 * \return A valid file full path (with name).
 */
std::string getValidFilePath();

#endif //SECSEMCOURSEWORK_VALIDATION_H

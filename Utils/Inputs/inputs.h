//
// Created by CosmoPC on 04.04.2024.
//

#ifndef SECSEMCOURSEWORK_INPUTS_H
#define SECSEMCOURSEWORK_INPUTS_H

#include <iostream>

/**
 * \brief Get int user int input.
 *
 * \param welcomeMessage - message to display to the user
 * \param min - minimum value
 * \param max - maximum value
 *
 * \return int user input
 */
int getIntUserInput(const std::string& welcomeMessage, int min = 0, int max = INT_MAX);

/**
 * \brief Get string user input.
 *
 * \param welcomeMessage - message to display to the user
 *
 * \return string user input
 */
std::string getStringUserInput(const std::string& welcomeMessage);

#endif //SECSEMCOURSEWORK_INPUTS_H

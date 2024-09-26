//
// Created by CosmoPC on 03.04.2024.
//

#include "utils.h"

#include <sstream>
#include <iomanip>

std::pair<std::vector<int>, int> splitIntoDigits(double num) {
    std::vector<int> digits;
    std::stringstream stream;
    int dotPosition = -1;

    // Check if the number is an integer or has less than 5 decimal places
    if (num == static_cast<int>(num) || num * 100000 == static_cast<int>(num * 100000)) {
        stream << num; // Convert to string without changing precision
    } else {
        stream << std::fixed << std::setprecision(5) << num; // Set precision to 5
    }

    std::string numStr = stream.str();

    for (int i = 0; i < numStr.size(); i++) {
        if (numStr[i] == '.') {
            dotPosition = i;
        } else {
            // Ignore leading zero
            if (!(i == 0 && numStr[i] == '0')) {
                digits.push_back(numStr[i] - '0'); // Convert char to int
            }
        }
    }

    // Adjust the decimal point position if the number is less than 1
    if (num < 1) {
        dotPosition--;
    }

    return {digits, dotPosition};
}

double convertToNumber(const std::pair<std::vector<int>, int>& digitsAndDotPosition) {
    std::string numStr;
    for (int i : digitsAndDotPosition.first) {
        numStr += std::to_string(i);
    }

    // If a decimal point was found, insert it at the correct position
    if (digitsAndDotPosition.second != -1 && digitsAndDotPosition.second != digitsAndDotPosition.first.size()) {
        numStr.insert(digitsAndDotPosition.second, ".");
    }

    double result = std::stod(numStr);

    return result;
}



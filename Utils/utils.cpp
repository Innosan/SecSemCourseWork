//
// Created by CosmoPC on 03.04.2024.
//

#include "utils.h"

std::vector<int> splitIntoDigits(int num) {
    std::vector<int> digits;
    std::string numStr = std::to_string(num);

    for (char c : numStr) {
        digits.push_back(c - '0'); // Convert char to int
    }

    return digits;
};

int convertToNumber(const std::vector<int>& digits) {
    std::string numStr;
    for (int digit : digits) {
        numStr += std::to_string(digit);
    }
    int result = std::stoi(numStr);

    // Count the number of digits in the original number
    int originalDigits = digits.size();

    // Count the number of digits in the resulting number
    int resultDigits = result == 0 ? 1 : log10(result) + 1;

    // If the original number has more digits, add the difference as leading zeros
    if (originalDigits > resultDigits) {
        result *= pow(10, originalDigits - resultDigits);
    }

    return result;
};

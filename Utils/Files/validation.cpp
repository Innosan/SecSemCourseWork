#include <iostream>
#include <regex>
#include <fstream>

#include "validation.h"
#include "../Inputs/inputs.h"

using namespace std;

bool isFilePathValid(const string& filePath) {

    // Regular expression to match a valid file path (Windows)
    regex filePathRegex("^(?:[a-zA-Z]\\:|\\\\)\\\\([^\\\\]+\\\\)*[^\\/:*?\"<>|]+\\.csv$");

    if (!regex_match(filePath, filePathRegex)) {
        cerr << "Error: Invalid file path." << endl;
        return false;
    }

    return true;
}

bool isFileNameValid(const string& fileName) {
    string lowerCased = fileName;

    for (auto& x : lowerCased) {
        x = static_cast<char>(tolower(x));
    }

    // Regular expression to match a valid file name
    regex fileNameRegex("^[^\\/:*?\"<>|]+\\.csv");
    // Regular expression to match reserved file names in Windows
    regex fileNameReservedNames("^(?:CON|PRN|AUX|NUL|COM[1-9]|LPT[1-9]|con|prn|aux|nul|com[1-9]|lpt[1-9])(?:\\..*)?$");
    // Regular expression to match reserved characters in Windows file names
    regex fileNameReservedChars("[\\/:*?\"<>|]");

    if (!regex_match(lowerCased, fileNameRegex)) {
        cerr << "Error: Invalid file name." << endl;
        return false;
    }

    if (regex_match(lowerCased, fileNameReservedNames)) {
        cerr << "Error: Invalid file name. Using reserved filenames is prohibited!" << endl;
        return false;
    }

    if (regex_search(lowerCased, fileNameReservedChars)) {
        cerr << "Error: Invalid file name. Using reserved characters is prohibited!" << endl;
        return false;
    }

    return true;
}

string getValidFilePath() {
    string filename;
    string filepath;

    while (true) {
        filename = getStringUserInput("Input filename (only csv acceptable): ");

        if (isFileNameValid(filename)) {
            break;
        }
    }

    while (true) {
        filepath = getStringUserInput("Input path to file: ");

        if (isFilePathValid(filepath + filename)) {
            break;
        }
    }

    return filepath + filename;
}

// Function to check if a file exists
bool fileExists(const std::string& filename) {
    std::ifstream file(filename);
    return file.is_open();
}

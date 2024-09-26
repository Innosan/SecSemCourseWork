//
// Created by CosmoPC on 25.09.2024.
//

#ifndef SECSEMCOURSEWORK_ARRAYSORTER_H
#define SECSEMCOURSEWORK_ARRAYSORTER_H

#include <vector>
#include "../Utils/utils.h"
#include "ResultsHolder.h"

class ArraySorter {
public:
    static ArraySorter& getInstance() {
        static ArraySorter instance;
        return instance;
    }

    void setMatrix(const std::vector<std::vector<double>>& newMatrix) {
        this->matrix = newMatrix;
    }

    std::vector<std::vector<double>>& getMatrix() {
        return matrix;
    }

    void printMainMatrix() {
        printMatrix<double>(this->matrix, "Main matrix");
    }

    ResultsHolder& getResultsHolder() {
        return resultsHolder;
    }

    ArraySorter(const ArraySorter&) = delete;
    ArraySorter& operator=(const ArraySorter&) = delete;

private:
    std::vector<std::vector<double>> matrix;
    ResultsHolder& resultsHolder;

    // Private constructor and copy constructor to prevent creating more than one instance
    ArraySorter() : resultsHolder(ResultsHolder::getInstance()) {}
};

#endif //SECSEMCOURSEWORK_ARRAYSORTER_H

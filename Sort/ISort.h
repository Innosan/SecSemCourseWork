//
// Created by CosmoPC on 03.04.2024.
//

#ifndef SECSEMCOURSEWORK_ISORT_H
#define SECSEMCOURSEWORK_ISORT_H

#include <vector>
#include <iostream>
#include <functional>

enum SortOrder {
    ASC = 1,
    DESC = 2
};

template <typename T>
class ISort {
protected:
    int swapCount = 0;
    int compareCount = 0;

    std::function<bool(T, T)> compareOperation;

public:
    virtual void sort(std::vector<T>& array, int size, SortOrder sortOrder) = 0;

    void setComparisonOperation(SortOrder sortOrder) {
        if (sortOrder == ASC) {
            compareOperation = [](T a, T b) { return a > b; };
        } else {
            compareOperation = [](T a, T b) { return a < b; };
        }
    }

    void printCounters() {
        std::cout << "Swaps: " << swapCount << std::endl;
        std::cout << "Compares: " << compareCount << std::endl;
    }

    int getSwapCount() const {
        return swapCount;
    }

    int getCompareCount() const {
        return compareCount;
    }

    void resetCounters() {
        swapCount = 0;
        compareCount = 0;
    }

    virtual ~ISort() = default;
};


#endif //SECSEMCOURSEWORK_ISORT_H

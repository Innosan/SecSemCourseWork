//
// Created by CosmoPC on 03.04.2024.
//

#ifndef SECSEMCOURSEWORK_ISORT_H
#define SECSEMCOURSEWORK_ISORT_H

#include <vector>
#include <iostream>

template <typename T>
class ISort {
protected:
    int swapCount = 0;
    int compareCount = 0;

public:
    virtual void sort(std::vector<T>& array, int size) = 0;
    
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

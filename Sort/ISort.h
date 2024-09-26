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
    int sorterId = 0;
    std::string sorterName;

    std::function<bool(T, T)> compareOperation;

public:
    /**
     * Sort the array in place
     *
     * @param array - the array to be sorted
     * @param size - the size of the array
     * @param sortOrder - the order in which the array should be sorted
     *
     * @example quickSorter.sort(array, array.size(), ASC);
     */
    virtual void sort(std::vector<T>& array, int size, SortOrder sortOrder) = 0;

    /**
     * Set the comparison operation based on the sort order
     *
     * @param sortOrder - the order in which the array should be sorted
     */
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

    int getSortType() const {
        return sorterId;
    }

    std::string getSorterName() const {
        return sorterName;
    }

    virtual ~ISort() = default;
};


#endif //SECSEMCOURSEWORK_ISORT_H

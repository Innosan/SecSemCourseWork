//
// Created by CosmoPC on 06.04.2024.
//

#ifndef SECSEMCOURSEWORK_SELECTIONSORT_H
#define SECSEMCOURSEWORK_SELECTIONSORT_H

#include "../ISort.h"

template <typename T>
class SelectionSort : public ISort<T> {
public:
    SelectionSort() {
        this->sorterId = 3; // Assign a unique identifier to SelectionSort
        this->sorterName = "Selection Sort";
    }
    void sort(std::vector<T>& array, int size, SortOrder sortOrder) override {
        this->setComparisonOperation(sortOrder);

        for (int i = 0; i < size - 1; i++) {
            int minIndex = i;

            for (int j = i + 1; j < size; j++) {
                this->compareCount++;

                if (this->compareOperation(array[minIndex], array[j])) {
                    minIndex = j;
                }
            }

            // Swap the found minimum element with the first element
            if (minIndex != i) {
                std::swap(array[minIndex], array[i]);

                this->swapCount++;
            }
        }
    }
};

#endif //SECSEMCOURSEWORK_SELECTIONSORT_H

//
// Created by CosmoPC on 06.04.2024.
//

#ifndef SECSEMCOURSEWORK_INSERTIONSORT_H
#define SECSEMCOURSEWORK_INSERTIONSORT_H

#include "../ISort.h"

template <typename T>
class InsertionSort : public ISort<T> {
public:
    void sort(std::vector<T>& array, int size, SortOrder sortOrder) override {
        this->setComparisonOperation(sortOrder);

        for (int i = 1; i < size; i++) {
            T key = array[i];
            int j = i - 1;

            // Move elements of array[0..i-1], that are greater than key, to one position ahead of their current position
            while (j >= 0 && this->compareOperation(array[j], key)) {
                array[j + 1] = array[j];
                j = j - 1;

                this->swapCount++;
            }
            array[j + 1] = key;

            this->compareCount++;
        }
    }
};

#endif //SECSEMCOURSEWORK_INSERTIONSORT_H

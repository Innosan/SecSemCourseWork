//
// Created by CosmoPC on 03.04.2024.
//

#ifndef SECSEMCOURSEWORK_QUICKSORT_H
#define SECSEMCOURSEWORK_QUICKSORT_H

#include "../ISort.h"

template <typename T>
class QuickSort : public ISort<T> {
    int partition(std::vector<T>& array, int low, int high) {
        T pivot = array[high];
        int i = (low - 1);

        for (int j = low; j <= high - 1; j++) {
            this->compareCount++;

            if (array[j] < pivot) {
                i++;

                // Manually swap array[i] and array[j]
                T temp = array[i];
                array[i] = array[j];
                array[j] = temp;

                this->swapCount++;
            }
        }

        // Manually swap array[i + 1] and array[high]
        T temp = array[i + 1];
        array[i + 1] = array[high];
        array[high] = temp;

        this->swapCount++;

        return (i + 1);
    }

    void quickSort(std::vector<T>& array, int low, int high) {
        if (low < high) {
            int pi = partition(array, low, high);

            quickSort(array, low, pi - 1);
            quickSort(array, pi + 1, high);
        }
    }
public:
    void sort(std::vector<T>& array, int size) {
        quickSort(array, 0, size - 1);
    }
};


#endif //SECSEMCOURSEWORK_QUICKSORT_H

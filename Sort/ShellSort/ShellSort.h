//
// Created by CosmoPC on 06.04.2024.
//

#ifndef SECSEMCOURSEWORK_SHELLSORT_H
#define SECSEMCOURSEWORK_SHELLSORT_H

#include "../ISort.h"

template <typename T>
class ShellSort : public ISort<T> {
public:
    void sort(std::vector<T>& array, int size) override {

        // Start with a big gap, then reduce the gap
        for (int gap = size/2; gap > 0; gap /= 2) {

            // Do a gapped insertion sort for this gap size.
            // The first gap elements a[0..gap-1] are already in gapped order
            // keep adding one more element until the entire array is gap sorted
            for (int i = gap; i < size; i += 1) {

                // add a[i] to the elements that have been gap sorted
                // save a[i] in temp and make a hole at position i
                T temp = array[i];

                // shift earlier gap-sorted elements up until the correct location for a[i] is found
                int j;
                for (j = i; j >= gap && array[j - gap] > temp; j -= gap) {
                    array[j] = array[j - gap];

                    this->swapCount++;
                    this->compareCount++;
                }

                // put temp (the original a[i]) in its correct location
                array[j] = temp;
                this->swapCount++;
            }
        }
    }
};

#endif //SECSEMCOURSEWORK_SHELLSORT_H

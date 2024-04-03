//
// Created by CosmoPC on 03.04.2024.
//

#ifndef SECSEMCOURSEWORK_BUBBLESORT_H
#define SECSEMCOURSEWORK_BUBBLESORT_H


#include "../ISort.h"

template <typename T>
class BubbleSort : public ISort<T> {
public:
    void sort(std::vector<T>& array, int size) override {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                this->compareCount++;
                if (array[j] > array[j + 1]) {
                    // Swap the elements if they are in the wrong order
                    T temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;

                    this->swapCount++;
                }
            }
        }
    }
};


#endif //SECSEMCOURSEWORK_BUBBLESORT_H

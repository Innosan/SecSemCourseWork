#include "Sort/BubbleSort/BubbleSort.h"
#include "Sort/QuickSort/QuickSort.h"

#include "Utils/utils.h"

int main() {
    BubbleSort<int> bubbleSorter;
    QuickSort<int> quickSorter;

    std::vector<int> array = {1, 2, 3, 4, 5, 6, 7};

    bubbleSorter.sort(array, array.size());
    printVector(array, "Sorted array: ");
    bubbleSorter.printCounters();

    quickSorter.sort(array, array.size());
    printVector(array, "Sorted array: ");
    quickSorter.printCounters();

    return 0;
}

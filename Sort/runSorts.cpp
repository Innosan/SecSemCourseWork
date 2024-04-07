//
// Created by CosmoPC on 07.04.2024.
//

#include "runSorts.h"

#include "ISort.h"
#include "SelectionSort/SelectionSort.h"
#include "ShellSort/ShellSort.h"
#include "QuickSort/QuickSort.h"
#include "BubbleSort/BubbleSort.h"
#include "InsertionSort/InsertionSort.h"

#include "../Utils/utils.h"
#include "../Utils/tables.h"

void sorter(std::vector<int>& array) {
    SelectionSort<int> selectionSort;
    ShellSort<int> shellSort;
    QuickSort<int> quickSort;
    BubbleSort<int> bubbleSort;
    InsertionSort<int> insertionSort;

    // Create copies of the array for each sorting algorithm
    auto selectionArray = array;
    auto shellArray = array;
    auto quickArray = array;
    auto bubbleArray = array;
    auto insertionArray = array;

    // Sort the array using different sorting algorithms
    selectionSort.sort(selectionArray, selectionArray.size(), DESC);
    shellSort.sort(shellArray, shellArray.size(), DESC);
    quickSort.sort(quickArray, quickArray.size(), DESC);
    bubbleSort.sort(bubbleArray, bubbleArray.size(), DESC);
    insertionSort.sort(insertionArray, insertionArray.size(), DESC);

    // Print the results

    std::cout << "-----------------------------------" << std::endl;

    printVector(array, "Unsorted array: ");
    std::cout << std::endl << "---" << std::endl;

    printVector(selectionArray, "Selection sort: ");
    std::cout << std::endl << "---" << std::endl;

    printVector(shellArray, "Shell sort: ");
    std::cout << std::endl << "---" << std::endl;

    printVector(quickArray, "Quick sort: ");
    std::cout << std::endl << "---" << std::endl;

    printVector(bubbleArray, "Bubble sort: ");
    std::cout << std::endl << "---" << std::endl;

    printVector(insertionArray, "Insertion sort: ");
    std::cout << std::endl << "---" << std::endl;

    std::cout << "Results: " << std::endl;
    std::vector<std::vector<std::string>> results = {
            {"Algorithm", "Swaps", "Compares"},
            {"Selection Sort", std::to_string(selectionSort.getSwapCount()), std::to_string(selectionSort.getCompareCount())},
            {"Shell Sort", std::to_string(shellSort.getSwapCount()), std::to_string(shellSort.getCompareCount())},
            {"Quick Sort", std::to_string(quickSort.getSwapCount()), std::to_string(quickSort.getCompareCount())},
            {"Bubble Sort", std::to_string(bubbleSort.getSwapCount()), std::to_string(bubbleSort.getCompareCount())},
            {"Insertion Sort", std::to_string(insertionSort.getSwapCount()), std::to_string(insertionSort.getCompareCount())}
    };

    printTable(results);
}

void runSorts(std::vector<std::vector<int>>& matrix) {
    QuickSort<int> quickSort;

    // Sort each sliced element in the matrix
    for (auto& row : matrix) {
        for (auto& elem : row) {
            // TODO: ask if we should sort digits through SORTER with results printed

            std::vector<int> digits = splitIntoDigits(elem);

            quickSort.sort(digits, digits.size(), ASC);

            elem = convertToNumber(digits);
        }
    }

    int n = matrix.size(); // number of rows
    int m = matrix[0].size(); // number of columns

    for (int j = 0; j < m; ++j) {
        // Create a temporary vector and copy the j-th column into it
        std::vector<int> temp(n);
        for (int i = 0; i < n; ++i) {
            temp[i] = matrix[i][j];
        }

        // Running SORTER on the temporary vector (column)
        sorter(temp);

        // Sort the temporary vector
        quickSort.sort(temp, n, DESC);

        // Copy the sorted elements back into the j-th column
        for (int i = 0; i < n; ++i) {
            matrix[i][j] = temp[i];
        }
    }
}

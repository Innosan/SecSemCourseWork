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
#include "../Utils/Tables/tables.h"
#include "ArraySorter.h"

void sorter(std::vector<double>& array, const int order, SortOrder sortOrder = ASC) {
    SelectionSort<double> selectionSort;
    ShellSort<double> shellSort;
    QuickSort<double> quickSort;
    BubbleSort<double> bubbleSort;
    InsertionSort<double> insertionSort;

    // Create copies of the array for each sorting algorithm
    auto selectionArray = array;
    auto shellArray = array;
    auto quickArray = array;
    auto bubbleArray = array;
    auto insertionArray = array;

    // Get the ResultsHolder instance
    ArraySorter& arraySorter = ArraySorter::getInstance();
    ResultsHolder& resultsHolder = arraySorter.getResultsHolder();

    // Sort the array using different sorting algorithms and add the results to the ResultsHolder
    selectionSort.sort(selectionArray, selectionArray.size(), sortOrder);

    shellSort.sort(shellArray, shellArray.size(), sortOrder);

    quickSort.sort(quickArray, quickArray.size(), sortOrder);

    bubbleSort.sort(bubbleArray, bubbleArray.size(), sortOrder);

    insertionSort.sort(insertionArray, insertionArray.size(), sortOrder);

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
    std::vector<SortedArray> sortedArrays = {
            { "Selection Sort", selectionArray },
            { "Shell Sort", shellArray },
            { "Quick Sort", quickArray },
            { "Bubble Sort", bubbleArray },
            { "Insertion Sort", insertionArray }
    };

    std::vector<std::vector<std::string>> sortTable = {
            {"Algorithm", "Swaps", "Compares"},
            {"Selection Sort", std::to_string(selectionSort.getSwapCount()), std::to_string(selectionSort.getCompareCount())},
            {"Shell Sort", std::to_string(shellSort.getSwapCount()), std::to_string(shellSort.getCompareCount())},
            {"Quick Sort", std::to_string(quickSort.getSwapCount()), std::to_string(quickSort.getCompareCount())},
            {"Bubble Sort", std::to_string(bubbleSort.getSwapCount()), std::to_string(bubbleSort.getCompareCount())},
            {"Insertion Sort", std::to_string(insertionSort.getSwapCount()), std::to_string(insertionSort.getCompareCount())}
    };

    resultsHolder.addResult(array, sortTable, sortedArrays, order);

    printTable(sortTable);
}

void intSorter(std::vector<int>& array, const int order, SortOrder sortOrder = ASC) {
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

    // Get the ResultsHolder instance
    ArraySorter& arraySorter = ArraySorter::getInstance();
    ResultsHolder& resultsHolder = arraySorter.getResultsHolder();

    // Sort the array using different sorting algorithms and add the results to the ResultsHolder
    selectionSort.sort(selectionArray, selectionArray.size(), sortOrder);

    shellSort.sort(shellArray, shellArray.size(), sortOrder);

    quickSort.sort(quickArray, quickArray.size(), sortOrder);

    bubbleSort.sort(bubbleArray, bubbleArray.size(), sortOrder);

    insertionSort.sort(insertionArray, insertionArray.size(), sortOrder);

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
    std::vector<IntSortedArray> sortedArrays = {
            { "Selection Sort", selectionArray },
            { "Shell Sort", shellArray },
            { "Quick Sort", quickArray },
            { "Bubble Sort", bubbleArray },
            { "Insertion Sort", insertionArray }
    };

    std::vector<std::vector<std::string>>
            sortTable = {
            {"Algorithm", "Swaps", "Compares"},
            {"Selection Sort", std::to_string(selectionSort.getSwapCount()), std::to_string(selectionSort.getCompareCount())},
            {"Shell Sort", std::to_string(shellSort.getSwapCount()), std::to_string(shellSort.getCompareCount())},
            {"Quick Sort", std::to_string(quickSort.getSwapCount()), std::to_string(quickSort.getCompareCount())},
            {"Bubble Sort", std::to_string(bubbleSort.getSwapCount()), std::to_string(bubbleSort.getCompareCount())},
            {"Insertion Sort", std::to_string(insertionSort.getSwapCount()), std::to_string(insertionSort.getCompareCount())}
    };

    resultsHolder.addIntResult(array, sortTable, sortedArrays, order);

    printTable(sortTable);
}

void runSorts(std::vector<std::vector<double>>& matrix) {
    int sortsCount = 0;
    QuickSort<double> quickSort;
    QuickSort<int> digitQuickSort;

    // Sort each sliced element in the matrix
    for (auto& row : matrix) {
        for (auto& elem : row) {
            std::pair<std::vector<int>, int> digits = splitIntoDigits(elem);

            sortsCount++;
            // Sort the digits in ascending order
            intSorter(digits.first, sortsCount, ASC);

            digitQuickSort.sort(digits.first, digits.first.size(), ASC);

            elem = convertToNumber(digits);
        }
    }

    int n = matrix.size(); // number of rows
    int m = matrix[0].size(); // number of columns

    for (int j = 0; j < m; ++j) {
        // Create a temporary vector and copy the j-th column into it
        std::vector<double> temp(n);
        for (int i = 0; i < n; ++i) {
            temp[i] = matrix[i][j];
        }

        sortsCount++;

        // Running SORTER on the temporary vector (column)
        sorter(temp, sortsCount, DESC);

        // Sort the temporary vector
        quickSort.sort(temp, n, DESC);

        // Copy the sorted elements back into the j-th column
        for (int i = 0; i < n; ++i) {
            matrix[i][j] = temp[i];
        }
    }
}

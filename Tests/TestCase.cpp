//
// Created by CosmoPC on 26.09.2024.
//

#include "TestCase.h"
#include "../Sort/BubbleSort/BubbleSort.h"
#include "../Sort/SelectionSort/SelectionSort.h"
#include "../Sort/InsertionSort/InsertionSort.h"
#include "../Sort/ShellSort/ShellSort.h"
#include "../Sort/QuickSort/QuickSort.h"
#include "../Utils/utils.h"

#include <string>
#include <vector>


TestResult TestCase::runTest() {
    std::string message = "Test passed";
    std::vector<std::string> errors;

    auto sorters = std::vector<ISort<double>*> {
            new BubbleSort<double>(),
            new InsertionSort<double>(),
            new QuickSort<double>(),
            new SelectionSort<double>(),
            new ShellSort<double>()
    };

    for (auto sorter : sorters) {
        sorter->resetCounters();
        std::vector<double> arrayCopy = this->originalArray;
        sorter->sort(arrayCopy, arrayCopy.size(), this->sortOrder);

        if (arrayCopy != this->expectedSortedArray) {
            errors.emplace_back(sorter->getSorterName() + " failed");

            printVector(this->expectedSortedArray, "Expected");
            printVector(arrayCopy, "Actual");

            continue;
        }

        if (sorter->getSwapCount() != this->sortResults[sorter->getSortType()].first) {
            std::cout << sorter->getSorterName() << " swap count mismatch" << std::endl;
            std::cout << "Expected: " << this->sortResults[sorter->getSortType()].first << std::endl;
            std::cout << "Actual: " << sorter->getSwapCount() << std::endl;

            errors.emplace_back(sorter->getSorterName() + " swap count mismatch");
            continue;
        }

        if (sorter->getCompareCount() != this->sortResults[sorter->getSortType()].second) {
            std::cout << sorter->getSorterName() << " compare count mismatch" << std::endl;
            std::cout << "Expected: " << this->sortResults[sorter->getSortType()].second << std::endl;
            std::cout << "Actual: " << sorter->getCompareCount() << std::endl;

            errors.emplace_back(sorter->getSorterName() + " compare count mismatch");
            continue;
        }
    }

    bool testStatus = errors.empty();

    return {testStatus, this->name + ": " + message};
}

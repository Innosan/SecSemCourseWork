//
// Created by CosmoPC on 26.09.2024.
//

#ifndef SECSEMCOURSEWORK_TESTCASE_H
#define SECSEMCOURSEWORK_TESTCASE_H


#include <string>
#include <utility>
#include <vector>
#include "TestResult.h"
#include "../Sort/ISort.h"

class TestCase {
public:
    std::string name;
    SortOrder sortOrder;

    std::vector<double> originalArray;
    std::vector<double> expectedSortedArray;

    std::vector<std::pair<int, int>> sortResults;

    TestResult runTest();

    TestCase(
        std::string name, SortOrder sortOrder, std::vector<double> originalArray, std::vector<double> expectedSortedArray,
        const std::vector<std::pair<int, int>>& sortResults = {})
         :
        name(std::move(name)),
        sortOrder(sortOrder),
        originalArray(std::move(originalArray)),
        expectedSortedArray(std::move(expectedSortedArray)),
        sortResults(sortResults)
        {};
};


#endif //SECSEMCOURSEWORK_TESTCASE_H

//
// Created by CosmoPC on 26.09.2024.
//

#include "TestCase.h"

void runMainTests() {
    std::vector<TestCase> testCases = {
        {
            "Test 1 - No sorting required",
            SortOrder::ASC,
            std::vector<double>{1, 2, 3, 4, 5},
            std::vector<double>{1, 2, 3, 4, 5},
            {
                {0, 10}, {0, 4}, {14, 10}, {0, 10}, {7, 0}
            }
        },
        {
            "Test 2 - Descending order",
            SortOrder::DESC,
            std::vector<double>{1, 2, 3, 4, 5},
            std::vector<double>{5, 4, 3, 2, 1},
            {
                {10, 10}, {10, 4}, {8, 10}, {2, 10}, {11, 4}
            }
        },
        {
            "Test 3 - Random order",
            SortOrder::ASC,
            std::vector<double>{5, 1, 3, 2, 4},
            std::vector<double>{1, 2, 3, 4, 5},
            {
                {5, 10}, {5, 4}, {6, 6}, {3, 10}, {12, 5}
            }
        },
        {
            "Test 4 - Negative values",
            SortOrder::ASC,
            std::vector<double>{-5, -1, -3, -2, -4},
            std::vector<double>{-5, -4, -3, -2, -1},
            {
                {5, 10}, {5, 4}, {7, 7}, {1, 10}, {12, 5}
            }
        },
        {
            "Test 5 - Mixed values",
            SortOrder::ASC,
            std::vector<double>{-5, 1, 3, -2, 4},
            std::vector<double>{-5, -2, 1, 3, 4},
            {
                {2, 10}, {2, 4}, {8, 8}, {2, 10}, {9, 2}
            }
        }
    };

    bool allTestsPassed = true;

    for (auto& testCase : testCases) {
        TestResult result = testCase.runTest();

        if (!result.status) {
            std::cout << "Test failed: " << testCase.name << std::endl;
            std::cout << result.message << std::endl;

            allTestsPassed = false;
        }
    }

    if (allTestsPassed) {
        std::cout << "All tests passed successfully" << std::endl;
    } else {
        std::cout << "Some tests failed" << std::endl;
    }
}
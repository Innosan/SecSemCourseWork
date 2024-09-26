//
// Created by CosmoPC on 26.09.2024.
//

#ifndef SECSEMCOURSEWORK_RESULTSHOLDER_H
#define SECSEMCOURSEWORK_RESULTSHOLDER_H

#include <string>
#include <utility>
#include <vector>
#include <fstream>
#include <iostream>
#include <variant>
#include <functional>
#include <iomanip>
#include "../Utils/Files/validation.h"
#include "../Utils/Files/files.h"

struct SortedArray {
    std::string algorithm;
    std::vector<double> array;
};

struct IntSortedArray {
    std::string algorithm;
    std::vector<int> array;
};

class ResultsHolder {
public:
    static ResultsHolder& getInstance() {
        static ResultsHolder instance;
        return instance;
    }

    void addResult(const std::vector<double>& array, std::vector<std::vector<std::string>> sortTable, std::vector<SortedArray> sortedArrays, const int order) {
        Result result = { array, std::move(sortedArrays), std::move(sortTable), order };
        results.push_back(result);
    }

    void addIntResult(const std::vector<int>& array, std::vector<std::vector<std::string>> sortTable, std::vector<IntSortedArray> sortedArrays, const int order) {
        IntResult result = { array, std::move(sortedArrays), std::move(sortTable), order };
        intResults.push_back(result);
    }

    void clearResults() {
        results.clear();
        intResults.clear();
    }

    void exportCombinedResults() {
        struct CombinedResult {
            std::variant<Result, IntResult> result;
            int order;
        };

        std::string fullPath = getValidFilePath();
        fullPath = getOverwriteConfirmation(fullPath);

        // Try to open the file for writing
        std::ofstream file(fullPath);
        if (!file) {
            std::cerr << "Error: File is read-only or another error occurred." << std::endl;
            file.close();

            // Prompt the user to enter a new path
            while (true) {
                std::cout << "Please enter a new path." << std::endl;
                fullPath = getValidFilePath();
                fullPath = getOverwriteConfirmation(fullPath);

                // Try to open the new file for writing
                file.open(fullPath);
                if (file) {
                    break;
                }
                else {
                    std::cerr << "Error: File is read-only or another error occurred." << std::endl;
                    file.close();
                }
            }
        }

        std::vector<CombinedResult> combinedResults;

        combinedResults.reserve(results.size());
        for (const auto& result : results) {
            combinedResults.push_back({result, result.order});
        }

        for (const auto& intResult : intResults) {
            combinedResults.push_back({intResult, intResult.order});
        }

        std::sort(combinedResults.begin(), combinedResults.end(), [](const CombinedResult& a, const CombinedResult& b) {
            return a.order < b.order;
        });

        for (const auto& combinedResult : combinedResults) {
            std::visit([&file](auto&& arg) {
                using T = std::decay_t<decltype(arg)>;
                if constexpr (std::is_same_v<T, Result>) {
                    file << "Order: " << arg.order << "\n";
                    file << "Original Array: ";
                    for (const auto& val : arg.originalArray) {
                        file << std::fixed << std::setprecision(5) << val << " ";
                    }
                    file << "\n";

                    for (const auto& sortedArray : arg.sortedArrays) {
                        file << "---\n";
                        file << sortedArray.algorithm << ":\n";
                        for (const auto& val : sortedArray.array) {
                            file << std::fixed << std::setprecision(5) << val << " ";
                        }
                        file << "\n";
                    }

                    file << "---\n";
                    file << "Results:\n";
                    for (const auto& row : arg.sortTable) {
                        for (const auto& cell : row) {
                            file << std::setw(25) << std::left << cell;
                        }
                        file << "\n";
                    }
                    file << std::string(80, '-') << "\n";
                } else if constexpr (std::is_same_v<T, IntResult>) {
                    file << "Order: " << arg.order << "\n";
                    file << "Original Array: ";
                    for (const auto& val : arg.originalArray) {
                        file << val << " ";
                    }
                    file << "\n";

                    for (const auto& sortedArray : arg.sortedArrays) {
                        file << "---\n";
                        file << sortedArray.algorithm << ":\n";
                        for (const auto& val : sortedArray.array) {
                            file << val << " ";
                        }
                        file << "\n";
                    }

                    file << "---\n";
                    file << "Results:\n";
                    for (const auto& row : arg.sortTable) {
                        for (const auto& cell : row) {
                            file << std::setw(25) << std::left << cell;
                        }
                        file << "\n";
                    }
                    file << std::string(80, '-') << "\n";
                }
            }, combinedResult.result);
        }

        file.close();
    }

    ResultsHolder(const ResultsHolder&) = delete;
    ResultsHolder& operator=(const ResultsHolder&) = delete;

private:
    struct Result {
        std::vector<double> originalArray;
        std::vector<SortedArray> sortedArrays;
        std::vector<std::vector<std::string>> sortTable;
        int order;
    };

    struct IntResult {
        std::vector<int> originalArray;
        std::vector<IntSortedArray> sortedArrays;
        std::vector<std::vector<std::string>> sortTable;
        int order;
    };

    std::vector<Result> results;
    std::vector<IntResult> intResults;

    // Private constructor and copy constructor to prevent creating more than one instance
    ResultsHolder() = default;
};


#endif //SECSEMCOURSEWORK_RESULTSHOLDER_H

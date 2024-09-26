//
// Created by CosmoPC on 26.09.2024.
//

#ifndef SECSEMCOURSEWORK_TESTRESULT_H
#define SECSEMCOURSEWORK_TESTRESULT_H

#include <string>
#include <utility>

class TestResult
{
public:
    bool status;
    std::string message;

    TestResult(bool status, std::string message) : status(status), message(std::move(message)) {}
};


#endif //SECSEMCOURSEWORK_TESTRESULT_H

//
// Created by CosmoPC on 04.04.2024.
//

#ifndef SECSEMCOURSEWORK_MENUOPTION_H
#define SECSEMCOURSEWORK_MENUOPTION_H

#include <iostream>
#include <functional>
#include <utility>

class MenuOption {
    int id;
    std::string title;
    std::function<void()> action;

public:
    // constructor
    MenuOption(const int id, std::string title, const std::function<void()>& action)
            : id(id), title(std::move(title)), action(action) {}

    void print();
    void callAction();
};


#endif //SECSEMCOURSEWORK_MENUOPTION_H

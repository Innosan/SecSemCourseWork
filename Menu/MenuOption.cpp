//
// Created by CosmoPC on 04.04.2024.
//

#include <iostream>
#include "MenuOption.h"

void MenuOption::print() {
    std::cout << this->id << ". " << this->title << std::endl;
}

void MenuOption::callAction() {
    this->action();
}

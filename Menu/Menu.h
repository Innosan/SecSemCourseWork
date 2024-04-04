//
// Created by CosmoPC on 04.04.2024.
//

#ifndef SECSEMCOURSEWORK_MENU_H
#define SECSEMCOURSEWORK_MENU_H


#include <utility>
#include <vector>
#include "MenuOption.h"

class Menu {
    std::vector<MenuOption> options;

public:
    enum optionIds {
        LINE_BY_LINE = 1,
        FROM_FILE,
        RANDOM,
        EXIT
    };

    void initializeMenu();
    void display();

    static void printWelcomeMessage();

    /**
     * \brief Calling a menu action.
     *
     * \param index of option to call
     */
    void choose(int index);
};


#endif //SECSEMCOURSEWORK_MENU_H

#include <memory>

#include "Menu/Menu.h"
#include "Utils/Inputs/inputs.h"

int main() {
    Menu::printWelcomeMessage();
    std::unique_ptr<Menu> menu = std::make_unique<Menu>();
    menu->initializeMenu();

    int pickedItem = 0;
    do {
        menu->display();

        pickedItem = getIntUserInput("Choose an option: ", Menu::optionIds::LINE_BY_LINE - 1, Menu::optionIds::EXIT + 1);

        menu->choose(pickedItem);
    } while (pickedItem != Menu::optionIds::EXIT);

    return 0;
}

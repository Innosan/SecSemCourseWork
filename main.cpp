#include "Sort/BubbleSort/BubbleSort.h"
#include "Sort/QuickSort/QuickSort.h"

#include "Utils/utils.h"
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

//    BubbleSort<int> bubbleSorter;
//    QuickSort<int> quickSorter;
//
//    std::vector<int> array = {1, 2, 3, 4, 5, 6, 7};
//
//    bubbleSorter.sort(array, array.size());
//    printVector(array, "Sorted array: ");
//    bubbleSorter.printCounters();
//
//    quickSorter.sort(array, array.size());
//    printVector(array, "Sorted array: ");
//    quickSorter.printCounters();

    return 0;
}

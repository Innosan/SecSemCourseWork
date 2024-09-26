cmake_minimum_required(VERSION 3.27)
project(SecSemCourseWork)

set(CMAKE_CXX_STANDARD 17)

add_executable(SecSemCourseWork main.cpp
        Sort/ISort.cpp
        Sort/ISort.h
        Sort/BubbleSort/BubbleSort.cpp
        Sort/BubbleSort/BubbleSort.h
        Utils/utils.h
        Utils/utils.cpp
        Sort/QuickSort/QuickSort.cpp
        Sort/QuickSort/QuickSort.h
        Utils/Inputs/inputs.h
        Utils/Inputs/inputs.cpp
        Menu/Menu.cpp
        Menu/Menu.h
        Menu/MenuOption.cpp
        Menu/MenuOption.h
        Utils/Files/validation.h
        Utils/Files/validation.cpp
        Utils/Files/files.cpp
        Utils/Files/files.h
        Utils/randomGeneration.h
        Sort/InsertionSort/InsertionSort.cpp
        Sort/InsertionSort/InsertionSort.h
        Sort/SelectionSort/SelectionSort.cpp
        Sort/SelectionSort/SelectionSort.h
        Sort/ShellSort/ShellSort.cpp
        Sort/ShellSort/ShellSort.h
        Sort/runSorts.h
        Sort/runSorts.cpp
        Utils/Tables/tables.cpp
        Utils/Tables/tables.h
        Sort/ArraySorter.cpp
        Sort/ArraySorter.h
        Sort/ResultsHolder.cpp
        Sort/ResultsHolder.h
        Tests/TestCase.cpp
        Tests/TestCase.h
        Tests/TestResult.cpp
        Tests/TestResult.h
        Tests/runMainTests.cpp
        Tests/runMainTests.h)

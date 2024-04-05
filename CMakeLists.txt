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
        Utils/randomGeneration.h)

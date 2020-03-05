//
// Created by felz on 03.03.2020.
//

#include "Animations.h"

#include<iostream>
#include <chrono>
#include <thread>

void clearScreen() {
    std::cout << std::string(50, '\n');
}

void battleIntroSequence() {
    int columns = 100;
    int rows = 100;

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns/10; j++) {
            std::cout << "__________";
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(5));
    }
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns/10; j++) {
            std::cout << "----------";
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(5));
    }
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns/10; j++) {
            std::cout << "..........";
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(5));
    }
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns/10; j++) {
            std::cout << "++++++++++";
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(5));
    }
    for(int i = 0; i < rows; i++) {
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        std::cout << std::endl;
    }

    clearScreen();

    std::cout << "('o')" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));;
    clearScreen();
    std::cout << "(/'o')/~O" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));;
    clearScreen();
    std::cout << "[placeholder]" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));;

    std::cout << "('o')" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));;
    clearScreen();
    std::cout << "O~\\('o'\\)" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));;
    clearScreen();
}
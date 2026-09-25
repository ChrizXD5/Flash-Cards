#include "clearScreen.hpp"
#include <iostream>

void clearScreen() {
    std::cout << "\033[H\033[2J\033[3J" << std::flush;
}
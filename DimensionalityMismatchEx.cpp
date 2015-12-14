#include <iostream>
#include "DimensionalityMismatchEx.h"

DimensionalityMismatchEx::DimensionalityMismatchEx(int option) {
    switch(option) {
        case 1:
            std::cout << "The dimensions used between two objects did not match.\n";
            break;
        case 2:
            std::cout << "The two objects are the same points.\n";
            break;
        default: std::cout << "Nothing\n";
    }
}

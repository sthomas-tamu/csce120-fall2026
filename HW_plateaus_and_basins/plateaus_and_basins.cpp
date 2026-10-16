// this file is provided. do not modify.

#include <iostream>
#include "functions.h"

int main() {
    bool quit = false;
    // We use int64_t because the input number can exceed the system's
    // limit for what an 32-bit integer can hold
    int64_t a = 0;
    int64_t b = 0;
    while (!quit) {
        std::cout << "Enter range: ";
        std::cin >> a >> b;
        if (a == 0) {
            quit = true;
            break;
        }
        while (!is_valid_range(a, b)) {
            std::cout << "Invalid Range" << std::endl;
            std::cout << "Enter range: ";
            std::cin >> a >> b;
        }
        plateaus_and_basins count = count_pb_numbers(a, b);
        std::cout << "There are " << count.plateaus << " plateaus"
                  << " and " << count.basins << " basins"
                  << " between " << a << " and " << b << "." << std::endl;
    }
    return 0;
}

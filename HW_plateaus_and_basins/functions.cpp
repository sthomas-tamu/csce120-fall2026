#include <iostream>
#include "functions.h"

// returns the boolean value true
// if and only if 1,000 <= a <= b < 1,000,000,000,000
bool is_valid_range(int64_t a, int64_t b) {
    if (1000 <= a && a <= b && b < 1000000000000) {
        return true;
    }
    return false;
}

// returns 'p' if number is a plateau,
//         'b' if number is a basin,
//         'n' if number is neither
char classify_geo_type(int64_t number) {
    int64_t original_number = number;

    // check for plateau: up, then flat, then down
    int64_t n = original_number;
    bool first_digit = true;
    int64_t previous_digit = 0;
    int stage = 1;
    bool went_up = false;
    bool is_plateau = true;

    while (n != 0) {
        int64_t digit = n % 10;
        n = n / 10;

        if (!first_digit) {
            if (stage == 1) {
                if (digit > previous_digit) {
                    went_up = true;
                } else if (digit == previous_digit && went_up) {
                    stage = 2;
                } else {
                    is_plateau = false;
                }
            } else if (stage == 2) {
                if (digit < previous_digit) {
                    stage = 3;
                } else if (digit != previous_digit) {
                    is_plateau = false;
                }
            } else {
                if (digit >= previous_digit) {
                    is_plateau = false;
                }
            }
        }

        previous_digit = digit;
        first_digit = false;
    }

    if (is_plateau && stage == 3) {
        return 'p';
    }

    // check for basin: down, then flat, then up
    n = original_number;
    first_digit = true;
    previous_digit = 0;
    stage = 1;
    bool went_down = false;
    bool is_basin = true;

    while (n != 0) {
        int64_t digit = n % 10;
        n = n / 10;

        if (!first_digit) {
            if (stage == 1) {
                if (digit < previous_digit) {
                    went_down = true;
                } else if (digit == previous_digit && went_down) {
                    stage = 2;
                } else {
                    is_basin = false;
                }
            } else if (stage == 2) {
                if (digit > previous_digit) {
                    stage = 3;
                } else if (digit != previous_digit) {
                    is_basin = false;
                }
            } else {
                if (digit <= previous_digit) {
                    is_basin = false;
                }
            }
        }

        previous_digit = digit;
        first_digit = false;
    }

    if (is_basin && stage == 3) {
        return 'b';
    }

    return 'n';
}

// returns how many numbers in the range [a, b] are plateaus and basins
plateaus_and_basins count_pb_numbers(int64_t a, int64_t b) {
    int number_of_plateaus = 0;
    int number_of_basins = 0;

    for (int64_t number = a; number <= b; number++) {
        char geo_type = classify_geo_type(number);
        if (geo_type == 'p') {
            number_of_plateaus++;
        } else if (geo_type == 'b') {
            number_of_basins++;
        }
    }

    return {number_of_plateaus, number_of_basins};
}

// Used AI for the first-digit logic. C++ requires every variable
// to have a starting value when declared, so previous_digit had to 
// be initialized to something and I used 0. But 0 isn't a real digit 
// from the number, so the first actual digit peeled shouldn't be 
// compared against it. Claude introduced a first_digit boolean flag, 
// checked with !first_digit, that skips the comparison on the very 
// first digit and only starts comparing once a real previous digit 
// exists.
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <cstdint>

// return the largest of the arguments
int largest(int a, int b, int c);

// return true if the sum of the arguments is even
bool sum_is_even(int a, int b);

/// return the number of boxes needed to store the given number of apples
int boxes_needed(int apples);

// return true if section A performs better than section B
// throws std::invalid_argument if the arguments are invalid
bool smarter_section(int A_correct, int A_total, int B_correct, int B_total);

// return true if you had a good dinner
bool good_dinner(int pizzas, bool is_weekend);

// return the sum of all integers from low to high (inclusive)
// throw std::invalid_argument if low and high are out of order
// throw std::overflow_error if the sum exceeds the maximum/minimum value of a signed 32-bit integer.
int32_t sum_between(int32_t low, int32_t high);

// return the product of a and b
// throw std::overflow_error if the product exceeds the maximum/minimum value of a signed 64-bit integer.
int64_t product(int64_t a, int64_t b);

#endif  // FUNCTIONS_H

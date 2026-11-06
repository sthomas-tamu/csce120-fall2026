/*
This is a driver for testing the functions.
You should add tests.
*/

#include <iostream>
#include <string>
#include <stdexcept>
#include <limits>
#include "functions.h"

// these are test helpers.  cool, right?
#define report_unexpected_exception std::cout << "[FAIL] (" << __func__ << ":" << __LINE__ << ") caught an unexpected exception." << std::endl; throw;
#define report_mismatch(expression,expected,actual) std::cout << "[FAIL] (" << __func__ << ":" << __LINE__ << ") expected " << expression << " to be " << expected << ", got " << actual << std::endl;

#define expect_eq(A,X) {\
int64_t actual, expected;\
try { actual = A; expected = X; } catch (...) { report_unexpected_exception }\
if (!(actual == expected)) { report_mismatch(#A,expected,actual) } }

#define expect_true(A) {\
bool actual;\
try { actual = A; } catch (...) { report_unexpected_exception }\
if (!actual) { report_mismatch(#A,"true","false") } }

#define expect_false(A) {\
bool actual;\
try { actual = A; } catch (...) { report_unexpected_exception }\
if (actual) { report_mismatch(#A,"false","true") } }

#define expect_throw(A,X) {\
try { A; report_mismatch(#A,"\b\b\bthrow " + std::string(#X),"nothing") } catch (const X& err) {  } catch (...) { report_unexpected_exception } }

/*
test helper usage examples:
expect_eq(1 + 2, 3);
expect_true(1 + 2 == 3);
expect_false(1 + 2 == 4);
expect_throw(throw std::invalid_argument("hi"), std::invalid_argument);
*/

void test_largest() {
    // largest(3, 2, 1) should return 3
    expect_eq(largest(1, 2, 3), 3);
    expect_eq(largest(3, 2, 1), 3);
    expect_eq(largest(1, 3, 2), 3);
    expect_eq(largest(5, 5, 5), 5);
    expect_eq(largest(-1, -2, -3), -1);
    expect_eq(largest(-10, 0, -5), 0);
}

void test_sum_is_even() {
    // sum_is_even(3, 5) should return true
    expect_true(sum_is_even(3, 5));
    expect_true(sum_is_even(2, 4));
    expect_false(sum_is_even(1, 2));
    expect_true(sum_is_even(0, 0));
    expect_true(sum_is_even(-3, -5));
    expect_false(sum_is_even(-3, 0));
}

void test_boxes_needed() {
    // boxes_needed(-13) should return 0
    expect_eq(boxes_needed(13), 1);
    expect_eq(boxes_needed(0), 0);
    expect_eq(boxes_needed(-13), 0);
    expect_eq(boxes_needed(20), 1);
    expect_eq(boxes_needed(21), 2);
    expect_eq(boxes_needed(40), 2);
    expect_eq(boxes_needed(41), 3);
    expect_eq(boxes_needed(1), 1);
    expect_eq(boxes_needed(19), 1);
    // big values: adding before dividing would overflow here
    expect_eq(boxes_needed(2147483640), 107374182);
    expect_eq(boxes_needed(2147483647), 107374183);
    expect_eq(boxes_needed(std::numeric_limits<int>::min()), 0);
}

void test_smarter_section() {
    // smarter_section(40, 50, 75, 100) should return true
    expect_true(smarter_section(40, 50, 75, 100));
    expect_false(smarter_section(75, 100, 40, 50));
    // a tie is not "better"
    expect_false(smarter_section(1, 2, 2, 4));
    // integer division would make both of these 0
    expect_true(smarter_section(3, 10, 2, 10));
    expect_throw(smarter_section(1, 0, 1, 2), std::invalid_argument);
    expect_throw(smarter_section(1, 2, 1, -5), std::invalid_argument);
    expect_throw(smarter_section(5, 2, 1, 2), std::invalid_argument);
    expect_throw(smarter_section(-1, 2, 1, 2), std::invalid_argument);
}

void test_good_dinner() {
    // good_dinner(13, false) should return true
    expect_true(good_dinner(13, false));
    expect_true(good_dinner(10, false));
    expect_true(good_dinner(20, false));
    expect_false(good_dinner(9, false));
    expect_false(good_dinner(21, false));
    expect_false(good_dinner(9, true));
    expect_true(good_dinner(100, true));
    expect_false(good_dinner(0, true));
}

void test_sum_between() {
    // sum_between(1, 10) should return 55
    expect_eq(sum_between(1, 10), 55);
    expect_eq(sum_between(5, 5), 5);
    expect_eq(sum_between(-3, 3), 0);
    expect_eq(sum_between(-5, -1), -15);
    expect_eq(sum_between(0, 0), 0);
    // this one cancels out even though the pieces are huge
    expect_eq(sum_between(std::numeric_limits<int32_t>::min(), 2147483647), -2147483648);
    expect_throw(sum_between(10, 1), std::invalid_argument);
    expect_throw(sum_between(1, 2147483647), std::overflow_error);
    expect_throw(sum_between(std::numeric_limits<int32_t>::min(), 0), std::overflow_error);
}

void test_product() {
    // product(2, 2) should return 4
    expect_eq(product(2, 2), 4);
    expect_eq(product(-3, 4), -12);
    expect_eq(product(-3, -4), 12);
    expect_eq(product(0, 9223372036854775807), 0);
    expect_eq(product(1, 9223372036854775807), 9223372036854775807);
    expect_throw(product(9223372036854775807, 2), std::overflow_error);
    expect_throw(product(std::numeric_limits<int64_t>::min(), -1), std::overflow_error);
    expect_throw(product(-3037000500, 3037000500), std::overflow_error);
    expect_throw(product(-3037000500, -3037000500), std::overflow_error);
}

int main() {
    test_largest();
    test_sum_is_even();
    test_boxes_needed();
    test_smarter_section();
    test_good_dinner();
    test_sum_between();
    test_product();

    return 0;
}

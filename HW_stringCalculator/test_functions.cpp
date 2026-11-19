#include <iostream>
#include "functions.h"
#include "test.h"

string remove_leading_zeros(string number);
string make_negative(const string& number);
bool is_smaller(const string& a, const string& b);
string multiply_by_digit(const string& a, int digit);

// assert_equal only works with strings
string bool_to_string(bool value) {
    if (value) {
        return "true";
    }
    return "false";
}

void test_helpers() {
    assert_equal(remove_leading_zeros("000"), "0");
    assert_equal(remove_leading_zeros("00120"), "120");
    assert_equal(remove_leading_zeros("5"), "5");
    assert_equal(make_negative("0"), "0");
    assert_equal(make_negative("7"), "-7");
    assert_equal(bool_to_string(is_smaller("99", "100")), "true");
    assert_equal(bool_to_string(is_smaller("100", "99")), "false");
    assert_equal(bool_to_string(is_smaller("123", "124")), "true");
    assert_equal(bool_to_string(is_smaller("125", "124")), "false");
    assert_equal(bool_to_string(is_smaller("124", "124")), "false");
    assert_equal(multiply_by_digit("99", 9), "891");
    assert_equal(multiply_by_digit("123", 0), "0");
}

void test_add() {
    assert_equal(add("1", "1"), "2");
    assert_equal(add("0", "0"), "0");
    assert_equal(add("47349", "6232"), "53581");
    assert_equal(add("999", "1"), "1000");
    assert_equal(add("99999999999999999999", "1"), "100000000000000000000");
    assert_equal(add("-5", "-7"), "-12");
    assert_equal(add("-5", "7"), "2");
    assert_equal(add("5", "-7"), "-2");
    assert_equal(add("7", "-7"), "0");
    assert_equal(add("007", "003"), "10");
}

void test_subtract() {
    assert_equal(subtract("1", "1"), "0");
    assert_equal(subtract("5309", "867"), "4442");
    assert_equal(subtract("867", "5309"), "-4442");
    assert_equal(subtract("1000", "1"), "999");
    assert_equal(subtract("5", "-3"), "8");
    assert_equal(subtract("-5", "3"), "-8");
    assert_equal(subtract("-5", "-3"), "-2");
    assert_equal(subtract("-3", "-5"), "2");
    assert_equal(subtract("-0", "0"), "0");
}

void test_multiply() {
    assert_equal(multiply("1", "1"), "1");
    assert_equal(multiply("0", "12345"), "0");
    assert_equal(multiply("867", "5309"), "4602903");
    assert_equal(multiply("99999999999999999999", "99999999999999999999"),
                 "9999999999999999999800000000000000000001");
    assert_equal(multiply("-3", "4"), "-12");
    assert_equal(multiply("3", "-4"), "-12");
    assert_equal(multiply("-3", "-4"), "12");
    assert_equal(multiply("-5", "0"), "0");
}

int main() {
    test_helpers();
    test_add();
    test_subtract();
    test_multiply();
    return 0;
}

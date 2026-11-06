#include <iostream>
#include <string>
#include "functions.h"

using std::string;

// removes extra zeros at the front, e.g. "00120" becomes "120"
string remove_leading_zeros(string number) {
    while (number.size() > 1 && number[0] == '0') {
        number.erase(0, 1);
    }
    return number;
}

// don't want to return "-0"
string make_negative(const string& number) {
    if (number == "0") {
        return "0";
    }
    return "-" + number;
}

// true if a < b (both positive, no leading zeros)
bool is_smaller(const string& a, const string& b) {
    if (a.size() != b.size()) {
        return a.size() < b.size();
    }
    for (int i = 0; i < int(a.size()); i++) {
        if (a[i] != b[i]) {
            return a[i] < b[i];
        }
    }
    return false;
}

string add_positive(string a, string b) {
    // make them the same length
    while (a.size() < b.size()) a = "0" + a;
    while (b.size() < a.size()) b = "0" + b;

    string result = "";
    int carry = 0;
    for (int i = int(a.size()) - 1; i >= 0; i--) {
        int sum = (a[i] - '0') + (b[i] - '0') + carry;
        carry = sum / 10;
        result = char(sum % 10 + '0') + result;
    }
    if (carry == 1) {
        result = "1" + result;
    }
    return remove_leading_zeros(result);
}

// assumes a >= b
string subtract_positive(string a, string b) {
    while (b.size() < a.size()) b = "0" + b;

    string result = "";
    int borrow = 0;
    for (int i = int(a.size()) - 1; i >= 0; i--) {
        int diff = (a[i] - '0') - (b[i] - '0') - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result = char(diff + '0') + result;
    }
    return remove_leading_zeros(result);
}

string multiply_by_digit(const string& a, int digit) {
    string result = "";
    int carry = 0;
    for (int i = int(a.size()) - 1; i >= 0; i--) {
        int product = (a[i] - '0') * digit + carry;
        carry = product / 10;
        result = char(product % 10 + '0') + result;
    }
    if (carry > 0) {
        result = char(carry + '0') + result;
    }
    return remove_leading_zeros(result);
}

// long multiplication, same as by hand
string multiply_positive(const string& a, const string& b) {
    string total = "0";
    string zeros = "";
    for (int i = int(b.size()) - 1; i >= 0; i--) {
        string partial = multiply_by_digit(a, b[i] - '0') + zeros;
        total = add_positive(total, partial);
        zeros += "0";
    }
    return total;
}

string add(const string& lhs, const string& rhs) {
    bool lhs_negative = lhs[0] == '-';
    bool rhs_negative = rhs[0] == '-';
    string a = remove_leading_zeros(lhs_negative ? lhs.substr(1) : lhs);
    string b = remove_leading_zeros(rhs_negative ? rhs.substr(1) : rhs);

    if (!lhs_negative && !rhs_negative) {
        return add_positive(a, b);
    }
    if (lhs_negative && rhs_negative) {
        return make_negative(add_positive(a, b));
    }
    // one is negative, so it's really subtraction
    if (rhs_negative) {
        return subtract(a, b);
    }
    return subtract(b, a);
}

string subtract(const string& lhs, const string& rhs) {
    bool lhs_negative = lhs[0] == '-';
    bool rhs_negative = rhs[0] == '-';
    string a = remove_leading_zeros(lhs_negative ? lhs.substr(1) : lhs);
    string b = remove_leading_zeros(rhs_negative ? rhs.substr(1) : rhs);

    // a - (-b) = a + b
    if (!lhs_negative && rhs_negative) {
        return add_positive(a, b);
    }
    // -a - b = -(a + b)
    if (lhs_negative && !rhs_negative) {
        return make_negative(add_positive(a, b));
    }
    // -a - (-b) = b - a
    if (lhs_negative && rhs_negative) {
        return subtract(b, a);
    }

    // swap if b is bigger so we don't run out of digits to borrow from
    if (is_smaller(a, b)) {
        return make_negative(subtract_positive(b, a));
    }
    return subtract_positive(a, b);
}

string multiply(const string& lhs, const string& rhs) {
    bool lhs_negative = lhs[0] == '-';
    bool rhs_negative = rhs[0] == '-';
    string a = remove_leading_zeros(lhs_negative ? lhs.substr(1) : lhs);
    string b = remove_leading_zeros(rhs_negative ? rhs.substr(1) : rhs);

    string product = multiply_positive(a, b);
    if (lhs_negative != rhs_negative) {
        return make_negative(product);
    }
    return product;
}

// add more includes as necessary
#include "functions.h"
#include <string>
#include <iostream>
#include <sstream>

// deobfuscate a sentence
// arg 1: obfuscated sentence
// arg 2: deobfuscation details
// returns the deobfuscated sentence
std::string deobfuscate(std::string obfuscated_sentence, std::string deobfuscation_details) {
    std::string result = "";
    size_t pos = 0;

    for (size_t i = 0; i < deobfuscation_details.size(); i++) {
        int wordLength = deobfuscation_details.at(i) - '0';
        std::string word = obfuscated_sentence.substr(pos, wordLength);
        pos += wordLength;

        if (!word.empty()) {
            if (!result.empty()) {
                result += " ";
            }
            result += word;
        }
    }

    return result;
}

// replace filter word with octothorpes (#)
// arg 1: sentence
// arg 2: filter word
// returns the filtered sentence
std::string wordFilter(std::string sentence_to_filter, std::string word_to_filter_out) {
    if (word_to_filter_out.empty()) {
        return sentence_to_filter;
    }

    std::string replacement(word_to_filter_out.size(), '#');

    size_t pos = 0;
    while ((pos = sentence_to_filter.find(word_to_filter_out, pos)) != std::string::npos) {
        sentence_to_filter.replace(pos, word_to_filter_out.size(), replacement);
        pos += replacement.size();
    }

    return sentence_to_filter;
}

// convert a string to a secure password
// arg 1: text
// returns a secure password based on the text
std::string passwordConverter(std::string password) {
    // TODO(student): give the function parameter a descriptive name
    std::replace(password.begin(), password.end(), 'a', '@');
    std::replace(password.begin(), password.end(), 'e', '3');
    std::replace(password.begin(), password.end(), 'i', '!');
    std::replace(password.begin(), password.end(), 'o', '0');
    std::replace(password.begin(), password.end(), 'u', '^');
    // TODO(student): implement the function
    std::cout << "Updated Password: " << password << "\n";

    std::string flippedPassword(password.rbegin(), password.rend());
    password += flippedPassword;

    return password;
}

// calculate the result of an arithmetic expression in words
// arg 1: expression using words
// returns an arithmetic equation using numerals and arithmetic symbols
std::string wordCalculator(std::string arithmetic_expression_using_words) {
    std::istringstream stream(arithmetic_expression_using_words);
    std::string word;
    std::string output = "";
    int result = 0;
    bool haveResult = false;
    char pendingOp = 0;

    while (stream >> word) {
        if (word == "equals") {
            break;
        }

        int number = -1;
        std::string symbol = "";

        if (word == "zero") { number = 0; }
        else if (word == "one") { number = 1; }
        else if (word == "two") { number = 2; }
        else if (word == "three") { number = 3; }
        else if (word == "four") { number = 4; }
        else if (word == "five") { number = 5; }
        else if (word == "six") { number = 6; }
        else if (word == "seven") { number = 7; }
        else if (word == "eight") { number = 8; }
        else if (word == "nine") { number = 9; }
        else if (word == "plus") { symbol = "+"; }
        else if (word == "minus") { symbol = "-"; }
        else if (word == "times") { symbol = "*"; }
        else if (word == "divide") { symbol = "/"; }

        if (!symbol.empty()) {
            output += symbol + " ";
            pendingOp = symbol.at(0);
        } else {
            output += std::to_string(number) + " ";
            if (!haveResult) {
                result = number;
                haveResult = true;
            } else if (pendingOp == '+') {
                result += number;
            } else if (pendingOp == '-') {
                result -= number;
            } else if (pendingOp == '*') {
                result *= number;
            } else if (pendingOp == '/') {
                result /= number;
            }
        }
    }

    output += "= " + std::to_string(result);
    return output;
}

// count the palindromes in the text
// arg 1: text
// returns the number of palindromes in the text
unsigned int palindromeCounter(std::string words_separated_by_spaces) {
    unsigned int count = 0;
    std::string word = "";

    for (size_t i = 0; i <= words_separated_by_spaces.size(); i++) {
        // when we hit a space or the end of the string, "word" is complete
        if (i == words_separated_by_spaces.size() || words_separated_by_spaces.at(i) == ' ') {
            bool isPalindrome = true;
            for (size_t j = 0; j < word.size() / 2; j++) {
                char front = word.at(j);
                char back = word.at(word.size() - 1 - j);
                if (front >= 'A' && front <= 'Z') {
                    front += 'a' - 'A';
                }
                if (back >= 'A' && back <= 'Z') {
                    back += 'a' - 'A';
                }
                if (front != back) {
                    isPalindrome = false;
                    break;
                }
            }

            if (isPalindrome) {
                count++;
            }

            word = "";
        } else {
            word += words_separated_by_spaces.at(i);
        }
    }

    return count;
}

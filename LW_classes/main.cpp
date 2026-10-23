// this file is provided.  do not submit.
#include <iostream>
#include <string>
#include "functions.h"

void print(const std::string& line = "") {
    std::cout << line << std::endl;
}

void print_menu() {
    print("(1) Deobfuscate");
    print("(2) Word Filter");
    print("(3) Password Converter");
    print("(4) Word Calculator");
    print("(5) Palindrome Counter");
    print("(q) Quit Program");
}

std::string input(const std::string& prompt) {
    std::cout << prompt << std::endl;
    std::string line;
    std::getline(std::cin, line);
    return line;
}

void deobfuscate() {
    std::string sentence = input("Please enter obfuscated sentence: ");
    std::string details = input("Please enter deobfuscation details: ");
    std::string deobfuscated = deobfuscate(sentence, details);
    print("Deobfuscated sentence: " + deobfuscated);
}

void wordFilter() {
    std::string sentence = input("Please enter the sentence: ");
    std::string word = input("Please enter the filter word: ");
    std::string filtered = wordFilter(sentence, word);
    print("Filtered sentence: " + filtered);
}

void passwordConverter() {
    std::string text = input("Please enter your text: ");
    std::string password = passwordConverter(text);
    print("Password: " + password);
}

void wordCalculator() {
    std::string expression = input("Please enter word expression: ");
    std::string result = wordCalculator(expression);
    print(result);
}

void palindromeCounter() {
    std::string text = input("Please enter your words: ");
    unsigned int palindromes = palindromeCounter(text);
    print("You have typed " + std::to_string(palindromes) + " palindromes.");
}

int main() {
    char selection = 0;
    while (selection != 'q') {
        print_menu();
        try {
            selection = input("Select a function to run: ").at(0);
        } catch (const std::out_of_range& err) {
            selection = 0;
        }
        print();

        switch (selection) {
            case '1':
                deobfuscate();
                break;
            case '2':
                wordFilter();
                break;
            case '3':
                passwordConverter();
                break;
            case '4':
                wordCalculator();
                break;
            case '5':
                palindromeCounter();
                break;
            case 'q':
                print("Quitting");
                break;
            default:
                print("Invaid input");
        }

        print();
    }

    return 0;
}

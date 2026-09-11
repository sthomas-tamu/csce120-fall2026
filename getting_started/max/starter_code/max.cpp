#include <iostream>
#include <limits>

int main() {
    std::cout << "Enter 3 numbers." << std::endl;

    // Create a winner called max_num
    int max_num = std::numeric_limits<int>::lowest();

    // for loop for 3 times
    for (int i = 0; i < 3; i++) {
        // read in 1 number
        int currentNumber = 0;
        std::cin >> currentNumber;
        // check if it is bigger, if so update max_num
        if (currentNumber > max_num) {
            max_num = currentNumber;
        }
    }
    // print out max
    std::cout << "The largest number out of the three is " << max_num << std::endl;

    return 0;
}
#include <iostream>

int main() {
    int number;
    std::cin >> number;
    int last_digit = 1;
    if (number > 1) {
        int previous_digit = 1;
        for (int i = 1; i < number; ++i) {
            int tmp = last_digit;
            last_digit = (last_digit + previous_digit) % 10;
            previous_digit = tmp;
        }
    }

    std::cout << last_digit;

    return 0;
}
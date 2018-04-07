#include <iostream>

long count_fibonacci(int number) {
    if (number <= 2) {
        return 1;
    } else {
        return (count_fibonacci(number - 1) + count_fibonacci(number - 2));
    }
}

int main() {
    int number;
    std::cin >> number;

    int fibonacci;
    if (number <= 2) {
        fibonacci = 1;
    } else {
        int previous = fibonacci = 1;
        for (int i = 2; i < number; ++i) {
            int temp = fibonacci;
            fibonacci += previous;
            previous = temp;
        }
    }
    std::cout << fibonacci;

    return 0;
}
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
    std::cout << count_fibonacci(number);

    return 0;
}
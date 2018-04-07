#include <iostream>

int main() {
    int steps_number;
    std::cin >> steps_number;
    int routs_number;
    if (steps_number < 2) {
        routs_number = 1;
    } else if (steps_number == 2) {
        routs_number = 2;
    } else {
        int previous = 1;
        int before_previous = 1;
        routs_number = 2;
        for (int i = 2; i < steps_number; ++i) {
            int new_before_previous = previous;
            int new_previous = routs_number;
            routs_number += (previous + before_previous);
            before_previous = new_before_previous;
            previous = new_previous;
        }
    }

    std::cout << routs_number;


    return 0;
}
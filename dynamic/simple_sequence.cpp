#include <iostream>
#include <vector>

/*
    Sequence:
    a2n = an + an-1, 
    a2n+1 = an – an-1,
    a0 = a1 = 1.
*/

int main() {
    int number;
    std::cin >> number;

    std::vector<int> sequence(number + 2);
    sequence[0] = sequence[1] = 1;
    for (int i = 1; i <= number / 2; ++i) {
        sequence[2 * i] = sequence[i] + sequence[i - 1];
        sequence[2 * i + 1] = sequence[i] - sequence[i - 1];
    }

    std::cout << sequence[number];

    return 0;
}
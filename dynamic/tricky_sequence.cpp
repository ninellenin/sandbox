#include <iostream>
#include <vector>

/*
    a2n = an + 1 (n>0), 
    a2n+2 = a2n+1 - an (n>0),
    a0=1, a1=1.
*/
int main() {
    int number;
    std::cin >> number;

    std::vector<int> sequence(number + 2);
    sequence[0] = sequence[1] = 1;
    sequence[2] = 2;

    for (int i = 1; i <= number / 2; ++i) {
        sequence[2 * (i + 1)] = sequence[i + 1] + 1;
        sequence[2 * i + 1] = sequence[2 * (i + 1)] + sequence[i];
    }

    std::cout << sequence[number];

    return 0;
}
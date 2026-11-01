#include <iostream>
#include <algorithm>

int memo[101];

int getMinSteps(int n) {
    if (n == 1) return 0;
    if (memo[n] != -1) return memo[n];

    int r = 1 + getMinSteps(n - 1);

    if (n % 2 == 0)
        r = std::min(r, 1 + getMinSteps(n / 2));

    if (n % 3 == 0)
        r = std::min(r, 1 + getMinSteps(n / 3));

    return memo[n] = r;
}

int main() {
    std::fill(memo, memo + 101, -1);

    int n = 10;
    std::cout << "Input: " << n << std::endl;
    std::cout << "Minimum steps for n: " << getMinSteps(n) << std::endl;

    return 0;
}
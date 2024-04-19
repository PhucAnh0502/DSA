#include <iostream>

int hammingDistance(int x, int y) {
    return __builtin_popcount(x ^ y);
}

int main() {
    int x, y;
    std::cin >> x >> y;
    std::cout << hammingDistance(x, y) << std::endl;
    return 0;
}

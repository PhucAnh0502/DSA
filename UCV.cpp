#include <iostream>

int getCandidate(int n, int k) {
    int count = 0;
    while (n >= k) {
        n = n / k;
        count += 1;
    }
    return pow(k, count);
}

int main() {
    int n, k;
    std::cin >> n >> k;
    std::cout << getCandidate(n, k) << std::endl;
    return 0;
}

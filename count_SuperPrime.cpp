#include <iostream>

bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }

    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

int countSuperPrimes(int N) {
    int count = 0;

    for (int num = 1; num <= N; ++num) {
        if (isPrime(num)) {
            for (int i = 1; i < num; ++i) {
                if (isPrime(i) && isPrime(num - i)) {
                    count++;
                    break;
                }
            }
        }
    }

    return count;
}

int main() {
    int N;
    std::cin >> N;

    int superPrimeCount = countSuperPrimes(N);

    std::cout << superPrimeCount << std::endl;

    return 0;
}

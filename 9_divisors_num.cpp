#include <iostream>
#include <unordered_set>

int countNumbersWith9Divisors(int N) {
    int count = 0;

    for (int num = 1; num <= N; ++num) {
        std::unordered_set<int> divisors;
        for (int i = 1; i <= num; ++i) {
            if (num % i == 0) {
                divisors.insert(i);
                divisors.insert(num / i);
            }
            if (divisors.size() > 9) {
                break;
            }
        }

        if (divisors.size() == 9) {
            ++count;
        }
    }

    return count;
}

int main() {
    int N;
    std::cin >> N;

    int numberCount = countNumbersWith9Divisors(N);

    std::cout <<  numberCount << std::endl;

    return 0;
}

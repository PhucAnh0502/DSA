#include <iostream>

int getDigitSum(int num) {
    int digitSum = 0;
    while (num > 0) {
        digitSum += num % 10;
        num /= 10;
    }
    return digitSum;
}

int countNumbers(int N, int K) {
    int count = 0;
    for (int num = 1; num <= N; ++num) {
        int diff = num - getDigitSum(num);
        if (diff >= K) {
            count++;
        }
    }
    return count;
}

int main() {
    int N, K;
    std::cin >> N >> K;
    int result = countNumbers(N, K);
    std::cout << result << std::endl;
    return 0;
}

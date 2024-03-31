#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

int minimumCandyDifference(std::vector<int>& A, int M) {
    int N = A.size();
    if (M > N) {
        // Tru?ng h?p s? h?c sinh l?n hon s? gói k?o, không th? phân phát
        return -1;
    }

    std::sort(A.begin(), A.end()); // S?p x?p m?ng A[] theo th? t? tang d?n

    int minDifference = A[M - 1] - A[0]; // Giá tr? chênh l?ch t?i thi?u ban d?u
    for (int i = 1; i <= N - M; i++) {
        int difference = A[i + M - 1] - A[i];
        minDifference = std::min(minDifference, difference);
    }

    return minDifference;
}

int main() {
    std::vector<int> A;
    std::string input;

    std::getline(std::cin, input);
    std::istringstream iss(input);

    int num;
    while (iss >> num) {
        A.push_back(num);
    }

    int M;

    std::cin >> M;

    int minDifference = minimumCandyDifference(A, M);

    if (minDifference == -1) {
        std::cout << "Cannot distribute candies to more students than the number of packs." << std::endl;
    } else {
        std::cout <<  minDifference << std::endl;
    }

    return 0;
}


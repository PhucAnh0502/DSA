#include <iostream>
#include <vector>
#include <unordered_set>

int countNumbers(const std::vector<int>& arr) {
    int numCount = 0;
    std::unordered_set<int> numSet(arr.begin(), arr.end());

    for (int num : arr) {
        if (numSet.find(num + 1) != numSet.end()) {
            numCount++;
        }
    }

    return numCount;
}

int main() {
    int n;
    std::cout << "Nh?p s? ph?n t? c?a m?ng: ";
    std::cin >> n;

    std::vector<int> arr(n);
    std::cout << "Nh?p các ph?n t? c?a m?ng: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    int result = countNumbers(arr);
    std::cout << "S? lu?ng s? nguyên th?a mãn di?u ki?n là: " << result << std::endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

long long calculateMaxS(std::vector<int>& arr) {
    int n = arr.size();

    // S?p x?p m?ng arr theo th? t? không gi?m
    std::sort(arr.begin(), arr.end());

    long long maxS = 0;
    for (int i = 0; i < n; i++) {
        maxS += static_cast<long long>(arr[i]) * i;
    }

    return maxS;
}

int main() {
    int n;
    std::cout << "Nhap so luong phan tu cua mang: ";
    std::cin >> n;

    std::vector<int> arr(n);
    std::cout << "Nhap cac phan tu cua mang: ";
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    long long maxS = calculateMaxS(arr);
    std::cout << "Gia tri S lon nhat la: " << maxS << std::endl;

    return 0;
}

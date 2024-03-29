#include <iostream>
#include <vector>

void mergeArrays(std::vector<int>& arr1, int n, const std::vector<int>& arr2, int m) {
    int i = n - 1; // Ch? m?c cu?i cùng c?a arr1
    int j = m - 1; // Ch? m?c cu?i cùng c?a arr2
    int k = n + m - 1; // Ch? m?c cu?i cùng c?a m?ng h?p nh?t

    // H?p nh?t t? cu?i lên d?u
    while (i >= 0 && j >= 0) {
        if (arr1[i] > arr2[j]) {
            arr1[k] = arr1[i];
            i--;
        } else {
            arr1[k] = arr2[j];
            j--;
        }
        k--;
    }

    // Sao chép các ph?n t? còn l?i c?a arr2 (n?u có)
    while (j >= 0) {
        arr1[k] = arr2[j];
        j--;
        k--;
    }
}

int main() {
    int n, m;

    std::cout << "Nhap so luong phan tu cua mang arr1: ";
    std::cin >> n;
    std::vector<int> arr1(n);
    std::cout << "Nhap cac phan tu cua mang arr1 (sap xep tang dan): ";
    for (int i = 0; i < n; i++) {
        std::cin >> arr1[i];
    }

    std::cout << "Nhap so luong phan tu cua mang arr2: ";
    std::cin >> m;
    std::vector<int> arr2(m);
    std::cout << "Nhap cac phan tu cua mang arr2 (sap xep tang dan): ";
    for (int i = 0; i < m; i++) {
        std::cin >> arr2[i];
    }

    mergeArrays(arr1, n, arr2, m);

    std::cout << "Mang da hoi tu arr1 va arr2 (sap xep tang dan): ";
    for (int i = 0; i < n + m; i++) {
        std::cout << arr1[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

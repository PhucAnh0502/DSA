#include <iostream>
#include <vector>
#include <algorithm>

int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

int quickSelect(std::vector<int>& arr, int low, int high, int k) {
    if (low <= high) {
        int pivotIndex = partition(arr, low, high);

        if (k - 1 == pivotIndex) {
            return arr[pivotIndex];
        } else if (k - 1 < pivotIndex) {
            return quickSelect(arr, low, pivotIndex - 1, k);
        } else {
            return quickSelect(arr, pivotIndex + 1, high, k);
        }
    }

    return -1;  // Tru?ng h?p không tìm th?y ph?n t?
}

int findKthSmallest(std::vector<int>& arr, int k) {
    int size = arr.size();

    if (k > 0 && k <= size) {
        return quickSelect(arr, 0, size - 1, k);
    }

    return -1;  // Tru?ng h?p không tìm th?y ph?n t?
}

int main() {
    std::vector<int> arr;
    int num;

    std::cout << "Nhap cac phan tu cua mang (nhap -1 de ket thuc): ";
    while (true) {
        std::cin >> num;
        if (num == -1) {
            break;
        }
        arr.push_back(num);
    }

    int k;
    std::cout << "Nhap K: ";
    std::cin >> k;

    int kthSmallest = findKthSmallest(arr, k);

    if (kthSmallest != -1) {
        std::cout << "Phan tu nho thu " << k << " la: " << kthSmallest << std::endl;
    } else {
        std::cout << "Khong tim thay phan tu" << std::endl;
    }

    return 0;
}

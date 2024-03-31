#include <iostream>
#include <vector>
#include <string>
#include <sstream>

int findFloor(const std::vector<int>& arr, int x) {
    int n = arr.size();
    int low = 0;
    int high = n - 1;

    // N?u x l?n hon ph?n t? cu?i cùng c?a m?ng, thì floor là ph?n t? cu?i cùng
    if (x >= arr[high]) {
        return high;
    }

    // N?u x nh? hon ph?n t? d?u tiên c?a m?ng, không có floor
    if (x < arr[low]) {
        return -1;
    }

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x) {
            return mid;
        } else if (arr[mid] < x) {
            // Tìm floor bên ph?i c?a mid
            if (mid + 1 <= high && arr[mid + 1] > x) {
                return mid;
            }
            low = mid + 1; // Ti?p t?c tìm ki?m bên ph?i
        } else {
            // Tìm floor bên trái c?a mid
            if (mid - 1 >= low && arr[mid - 1] <= x) {
                return mid - 1;
            }
            high = mid - 1; // Ti?p t?c tìm ki?m bên trái
        }
    }

    return -1; // Không tìm th?y s? K trong m?ng
}

int main() {
    std::vector<int> arr;
    std::string input;

    std::getline(std::cin, input);
    std::istringstream iss(input);

    int num;
    while (iss >> num) {
        arr.push_back(num);
    }

    int x;
    
    std::cin >> x;

    int floorIndex = findFloor(arr, x);

    
    std::cout <<  floorIndex << std::endl;
    

    return 0;
}

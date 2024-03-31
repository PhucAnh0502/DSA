#include <iostream>
#include <vector>
#include <string>
#include <sstream>

int findFloor(const std::vector<int>& arr, int x) {
    int n = arr.size();
    int low = 0;
    int high = n - 1;

    // N?u x l?n hon ph?n t? cu?i c�ng c?a m?ng, th� floor l� ph?n t? cu?i c�ng
    if (x >= arr[high]) {
        return high;
    }

    // N?u x nh? hon ph?n t? d?u ti�n c?a m?ng, kh�ng c� floor
    if (x < arr[low]) {
        return -1;
    }

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x) {
            return mid;
        } else if (arr[mid] < x) {
            // T�m floor b�n ph?i c?a mid
            if (mid + 1 <= high && arr[mid + 1] > x) {
                return mid;
            }
            low = mid + 1; // Ti?p t?c t�m ki?m b�n ph?i
        } else {
            // T�m floor b�n tr�i c?a mid
            if (mid - 1 >= low && arr[mid - 1] <= x) {
                return mid - 1;
            }
            high = mid - 1; // Ti?p t?c t�m ki?m b�n tr�i
        }
    }

    return -1; // Kh�ng t�m th?y s? K trong m?ng
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

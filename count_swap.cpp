#include <iostream>
#include <vector>
#include <string>
#include <sstream>

int countSwapsToSort(std::vector<int>& arr) {
    int n = arr.size();
    int numSwaps = 0;

    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
                numSwaps++;
            }
        }
        if (!swapped) {
            // N?u kh�ng c� s? ho�n d?i trong v�ng l?p trong, m?ng d� du?c s?p x?p
            break;
        }
    }

    return numSwaps;
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

    int numSwaps = countSwapsToSort(arr);

    // In ra s? l?n d?o (swap)
    std::cout <<  numSwaps << std::endl;


    

    return 0;
}

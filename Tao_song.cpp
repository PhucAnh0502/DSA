#include <iostream>
#include <vector>
#include <algorithm>

void sortInWaveForm(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i += 2) {
        std::swap(arr[i], arr[i + 1]);
    }
}

int main() {
    std::vector<int> arr;

    int input;
    while (std::cin >> input && input != -1) {
        arr.push_back(input);
    }

    sortInWaveForm(arr);

    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

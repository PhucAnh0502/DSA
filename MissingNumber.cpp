#include <iostream>
#include <vector>
#include <unordered_set>

int findMissingNumber(const std::vector<int>& nums) {
    std::unordered_set<int> numSet;
    int n = nums.size();

    // Th�m c�c s? t? m?ng v�o set
    for (int num : nums) {
        numSet.insert(num);
    }

    // T�m s? nguy�n b? thi?u trong ph?m vi [0, n]
    for (int i = 0; i <= n; ++i) {
        if (numSet.find(i) == numSet.end()) {
            return i;
        }
    }

    return -1; // Tru?ng h?p kh�ng t�m th?y s? b? thi?u
}

int main() {
    int n;
    std::cin >> n;

    std::vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> nums[i];
    }

    int missingNumber = findMissingNumber(nums);
    std::cout <<  missingNumber << std::endl;

    return 0;
}

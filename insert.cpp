#include <iostream>
#include <vector>
#include <sstream>

std::vector<std::vector<int>> input2DArrayInt() {
    std::string line;
    std::vector<std::vector<int>> intervals;
    while (std::getline(std::cin, line)) {
        if (line.empty()) {
            break;
        }
        std::istringstream iss(line);
        std::vector<int> interval;
        int num;
        while (iss >> num) {
            interval.push_back(num);
        }
        intervals.push_back(interval);
    }
    return intervals;
}

std::vector<int> inputArrayInt() {
    std::string line;
    std::getline(std::cin, line);
    std::istringstream iss(line);
    std::vector<int> nums;
    int num;
    while (iss >> num) {
        nums.push_back(num);
    }
    return nums;
}

std::vector<std::vector<int>> insert(std::vector<std::vector<int>>& intervals, std::vector<int>& newInterval) {
    std::vector<std::vector<int>> result;
    std::vector<int> toAdd = newInterval;
    for (const auto& interval : intervals) {
        if (interval[0] > toAdd[1]) {
            result.push_back(toAdd);
            toAdd = interval;
        } else if (interval[1] >= toAdd[0]) {
            toAdd[0] = std::min(interval[0], toAdd[0]);
            toAdd[1] = std::max(interval[1], toAdd[1]);
        } else {
            result.push_back(interval);
        }
    }
    result.push_back(toAdd);
    return result;
}

int main() {
    std::vector<std::vector<int>> intervals = input2DArrayInt();
    std::vector<int> newInterval = inputArrayInt();
    std::vector<std::vector<int>> results = insert(intervals, newInterval);
    for (const auto& interval : results) {
        for (int i = 0; i < interval.size(); i++) {
            if (i == interval.size() - 1) {
                std::cout << interval[i];
            } else {
                std::cout << interval[i] << " ";
            }
        }
        std::cout << std::endl;
    }
    return 0;
}

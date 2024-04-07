#include <iostream>
#include <string>
#include <unordered_map>

int lengthOfLongestSubstring(const std::string& s) {
    if (s.empty()) {
        return 0;
    }
    std::unordered_map<char, int> map;
    int max = 0;
    for (int i = 0, j = 0; i < s.length(); ++i) {
        if (map.count(s[i])) {
            j = std::max(j, map[s[i]] + 1);
        }
        map[s[i]] = i;
        max = std::max(max, i - j + 1);
    }
    return max;
}

int main() {
    std::string s;
    std::getline(std::cin, s);
    std::cout << lengthOfLongestSubstring(s);

    return 0;
}

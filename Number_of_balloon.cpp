#include <iostream>
#include <string>
#include <algorithm>

int maxNumberOfBalloons(const std::string& text) {
    int chars[26] = {0};
    for (char c : text) {
        chars[c - 'a']++;
    }
    int min = chars[1];
    min = std::min(min, chars[0]);
    min = std::min(min, chars[11] / 2);
    min = std::min(min, chars[14] / 2);
    min = std::min(min, chars[13]);
    return min;
}

int main() {
    std::string text;
    std::getline(std::cin, text);
    std::cout << maxNumberOfBalloons(text);

    return 0;
}

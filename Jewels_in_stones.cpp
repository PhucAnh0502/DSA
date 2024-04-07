#include <iostream>
#include <string>
#include <vector>

int numJewelsInStones(const std::string& J, const std::string& S) {
    if (J.empty() || S.empty()) {
        return 0;
    }
    std::vector<int> jewels(58, 0);
    for (char c : J) {
        jewels[c - 'A'] = 1;
    }
    int result = 0;
    for (char c : S) {
        if (jewels[c - 'A'] == 1) {
            result++;
        }
    }
    return result;
}

int main() {
    std::string J;
    std::getline(std::cin, J);
    std::string S;
    std::getline(std::cin, S);
    std::cout << numJewelsInStones(J, S);

    return 0;
}

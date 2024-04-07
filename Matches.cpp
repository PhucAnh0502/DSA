#include <iostream>
#include <vector>
#include <map>
#include <sstream>

std::vector<std::vector<int>> input2DArrayInt() {
    std::string text;
    std::vector<std::vector<int>> twoDim;
    while (std::getline(std::cin, text)) {
        if (text.empty()) {
            break;
        }
        std::istringstream iss(text);
        std::vector<int> row;
        int num;
        while (iss >> num) {
            row.push_back(num);
        }
        twoDim.push_back(row);
    }
    return twoDim;
}

std::vector<std::vector<int>> findWinners(const std::vector<std::vector<int>>& matches) {
    std::map<int, int> losses;
    for (const auto& m : matches) {
        losses[m[0]] += 0;
        losses[m[1]] += 1;
    }
    std::vector<std::vector<int>> results(2);
    for (const auto& player : losses) {
        if (player.second <= 1) {
            results[player.second].push_back(player.first);
        }
    }
    return results;
}

int main() {
    std::vector<std::vector<int>> matches = input2DArrayInt();
    std::string result;
    std::vector<std::vector<int>> results = findWinners(matches);
    for (const auto& winners : results) {
        for (size_t i = 0; i < winners.size(); i++) {
            if (i != winners.size() - 1) {
                result += std::to_string(winners[i]) + " ";
            } else {
                result += std::to_string(winners[i]);
            }
        }
        result += "\n";
    }
    std::cout << result;

    return 0;
}

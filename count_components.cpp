#include <iostream>
#include <vector>
#include <sstream>

int find(std::vector<int>& roots, int id) {
    while (roots[id] != id) {
        roots[id] = roots[roots[id]];
        id = roots[id];
    }
    return id;
}

int countComponents(int n, const std::vector<std::vector<int>>& edges) {
    std::vector<int> roots(n);
    for (int i = 0; i < n; i++) {
        roots[i] = i;
    }
    for (const auto& e : edges) {
        int root1 = find(roots, e[0]);
        int root2 = find(roots, e[1]);
        if (root1 != root2) {
            roots[root1] = root2;
            n--;
        }
    }
    return n;
}

std::vector<std::vector<int>> input2DArrayInt() {
    std::string text;
    std::vector<std::vector<int>> twoDim;
    while (std::getline(std::cin, text)) {
        if (text.empty()) {
            break;
        }
        std::istringstream iss(text);
        std::vector<int> array;
        int value;
        while (iss >> value) {
            array.push_back(value);
        }
        twoDim.push_back(array);
    }
    return twoDim;
}

int main() {
    int n;
    std::cin >> n;
    std::cin.ignore();

    std::vector<std::vector<int>> edges = input2DArrayInt();

    std::cout << countComponents(n, edges);

    return 0;
}

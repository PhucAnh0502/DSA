#include <iostream>
#include <vector>
#include <sstream>
#include <queue>
#include <unordered_set>

int reachableNodes(int n, std::vector<std::vector<int>>& edges, std::vector<int>& restricted) {
    std::vector<std::vector<int>> al(n);
    for (int i = 0; i < n; i++) {
        al[i] = std::vector<int>();
    }
    for (auto e : edges) {
        int u = e[0];
        int v = e[1];
        al[u].push_back(v);
        al[v].push_back(u);
    }

    std::unordered_set<int> restrictedSet(restricted.begin(), restricted.end());
    std::queue<int> q;
    q.push(0);
    restrictedSet.insert(0);
    int ans = 0;

    while (!q.empty()) {
        int size = q.size();
        while (size-- > 0) {
            ans++;
            int curr = q.front();
            q.pop();
            for (auto next : al[curr]) {
                if (restrictedSet.insert(next).second) {
                    q.push(next);
                }
            }
        }
    }

    return ans;
}

std::vector<int> inputArrayInt() {
    std::string text;
    std::getline(std::cin, text);
    std::istringstream iss(text);
    std::vector<int> result;
    int value;
    while (iss >> value) {
        result.push_back(value);
    }
    return result;
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
    std::vector<int> restricted = inputArrayInt();
    std::cout << reachableNodes(n, edges, restricted);

    return 0;
}

#include <iostream>
#include <vector>
#include <unordered_set>
#include <sstream>

bool seen;

void dfs(const std::vector<std::unordered_set<int>>& graph, std::vector<bool>& visited, int start, int end) {
    if (!visited[start] && !seen) {
        if (start == end) {
            seen = true;
            return;
        }
        visited[start] = true;
        for (int neighbor : graph[start]) {
            dfs(graph, visited, neighbor, end);
        }
    }
}

bool validPath(int n, const std::vector<std::vector<int>>& edges, int start, int end) {
    std::vector<bool> visited(n, false);
    std::vector<std::unordered_set<int>> graph(n);
    for (const auto& edge : edges) {
        graph[edge[0]].insert(edge[1]);
        graph[edge[1]].insert(edge[0]);
    }
    if (graph[start].count(end)) {
        return true;
    }
    seen = false;
    dfs(graph, visited, start, end);
    return seen;
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
    int start, end;
    std::cin >> start >> end;

    std::cout << std::boolalpha << validPath(n, edges, start, end);

    return 0;
}

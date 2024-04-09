#include <iostream>
#include <vector>
#include <sstream>
#include <stack>

int maxAreaOfIsland(std::vector<std::vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    std::vector<std::vector<bool>> seen(rows, std::vector<bool>(cols, false));
    std::vector<int> dr = {1, -1, 0, 0};
    std::vector<int> dc = {0, 0, 1, -1};
    int ans = 0;

    for (int r0 = 0; r0 < rows; r0++) {
        for (int c0 = 0; c0 < cols; c0++) {
            if (grid[r0][c0] == 1 && !seen[r0][c0]) {
                int shape = 0;
                std::stack<std::pair<int, int>> st;
                st.push(std::make_pair(r0, c0));
                seen[r0][c0] = true;

                while (!st.empty()) {
                    auto node = st.top();
                    st.pop();
                    int r = node.first;
                    int c = node.second;
                    shape++;

                    for (int k = 0; k < 4; k++) {
                        int nr = r + dr[k];
                        int nc = c + dc[k];

                        if (nr >= 0 && nr < rows && nc >= 0 && nc < cols &&
                            grid[nr][nc] == 1 && !seen[nr][nc]) {
                            st.push(std::make_pair(nr, nc));
                            seen[nr][nc] = true;
                        }
                    }
                }
                ans = std::max(ans, shape);
            }
        }
    }

    return ans;
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
    std::vector<std::vector<int>> grid = input2DArrayInt();
    std::cout << maxAreaOfIsland(grid);

    return 0;
}

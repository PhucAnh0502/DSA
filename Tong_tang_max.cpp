#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> a(n);
    for (int i = 0; i < n; ++i) {
        a[i] = std::vector<int>(m);
        for (int j = 0; j < m; ++j) {
            std::cin >> a[i][j];
        }
        std::sort(a[i].rbegin(), a[i].rend());
    }

    try {
        for (int i = n - 2; i >= 0; --i) {
            int point = 0;
            while (a[i][0] >= a[i + 1][0]) {
                a[i].erase(a[i].begin());
                if (a[i].empty()) {
                    break;
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i].empty()) {
                ans = 0;
                break;
            }
            ans += a[i][0];
        }

        std::cout << ans << std::endl;
    } catch (...) {
        std::cout << 0 << std::endl;
    }

    return 0;
}

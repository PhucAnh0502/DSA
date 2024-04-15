#include <iostream>
#include <vector>

void dfs(int src, int k, int n, std::vector<int>& lst, std::vector<std::vector<int>>& ls) {
    k--;
    n -= src;
    lst.push_back(src);
    if (k == 0 && n == 0) {
        std::vector<int> tl(lst);
        ls.push_back(tl);
        lst.pop_back();
        return;
    } else if (k == 0) {
        lst.pop_back();
        return;
    } else {
        int tmp = src;
        while (tmp++ < 9) {
            dfs(tmp, k, n, lst, ls);
        }
        lst.pop_back();
    }
}

std::vector<std::vector<int>> combinationSum3(int k, int n) {
    std::vector<std::vector<int>> lst;
    for (int i = 1; i <= 9 - (k - 1); i++) {
        std::vector<int> temp;
        dfs(i, k, n, temp, lst);
    }
    return lst;
}

int main() {
    int k, n;
    std::cin >> k >> n;

    std::vector<std::vector<int>> results = combinationSum3(k, n);

    for (int i = 0; i < results.size(); i++) {
        for (int j = 0; j < results[i].size(); j++) {
            if (j < results[i].size() - 1) {
                std::cout << results[i][j] << " ";
            } else {
                std::cout << results[i][j];
            }
        }
        if (i < results.size() - 1) {
            std::cout << "\n";
        }
    }

    return 0;
}

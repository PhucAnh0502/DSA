#include <iostream>
#include <vector>
using namespace std;

int coinChange(vector<int>& coins, int amount) {
    if (amount < 1) {
        return 0;
    }
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < coins.size(); j++) {
            if (coins[j] <= i && dp[i - coins[j]] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }
    return dp[amount] == INT_MAX ? -1 : dp[amount];
}

vector<int> inputArrayInt() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    int num;
    vector<int> result;
    while (ss >> num) {
        result.push_back(num);
    }
    return result;
}

int main() {
    vector<int> cost = inputArrayInt();
    int amount;
    cin >> amount;
    cout << coinChange(cost, amount) << endl;
    return 0;
}

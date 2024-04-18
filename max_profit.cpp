#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices, int fee) {
    int cash = 0, hold = -prices[0];
    for (int i = 1; i < prices.size(); i++) {
        cash = max(cash, hold + prices[i] - fee);
        hold = max(hold, cash - prices[i]);
    }
    return cash;
}

vector<int> inputArrayInt() {
    string text;
    getline(cin, text);
    vector<int> result;
    size_t pos = 0;
    while ((pos = text.find(" ")) != string::npos) {
        string numStr = text.substr(0, pos);
        result.push_back(stoi(numStr));
        text.erase(0, pos + 1);
    }
    result.push_back(stoi(text));
    return result;
}

int main() {
    vector<int> prices = inputArrayInt();
    int fee;
    cin >> fee;
    cout << maxProfit(prices, fee) << endl;
    return 0;
}

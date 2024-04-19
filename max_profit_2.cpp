#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices) {
    if (prices.empty() || prices.size() <= 1) {
        return 0;
    }
    int b0 = -prices[0], b1 = b0;
    int s0 = 0, s1 = 0, s2 = 0;
    for (int i = 1; i < prices.size(); i++) {
        b0 = max(b1, s2 - prices[i]);
        s0 = max(s1, b1 + prices[i]);
        b1 = b0;
        s2 = s1;
        s1 = s0;
    }
    return s0;
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
    cout << maxProfit(prices) << endl;
    return 0;
}

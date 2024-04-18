#include <iostream>
#include <vector>
using namespace std;

int minCostClimbingStairs(vector<int>& cost) {
    for (int i = 2; i < cost.size(); i++) {
        cost[i] += min(cost[i - 1], cost[i - 2]);
    }
    return min(cost[cost.size() - 1], cost[cost.size() - 2]);
}

vector<int> inputArrayInt() {
    string text;
    getline(cin, text);
    vector<int> result;
    size_t pos = 0;
    while ((pos = text.find(' ')) != string::npos) {
        result.push_back(stoi(text.substr(0, pos)));
        text.erase(0, pos + 1);
    }
    result.push_back(stoi(text));
    return result;
}

int main() {
    vector<int> cost = inputArrayInt();
    cout << minCostClimbingStairs(cost) << endl;
    return 0;
}

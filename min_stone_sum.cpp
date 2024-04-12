#include <iostream>
#include <vector>
#include <queue>
#include <sstream>

using namespace std;

int minStoneSum(vector<int>& piles, int k) {
    priority_queue<int> heap;
    for (int num : piles) {
        heap.push(num);
    }
    
    for (int i = 0; i < k; i++) {
        int curr = heap.top();
        heap.pop();
        int remove = curr / 2;
        heap.push(curr - remove);
    }
    
    int ans = 0;
    while (!heap.empty()) {
        ans += heap.top();
        heap.pop();
    }
    
    return ans;
}

vector<int> inputArrayInt() {
    string line;
    getline(cin, line);
    istringstream iss(line);
    vector<int> result;
    int num;
    while (iss >> num) {
        result.push_back(num);
    }
    return result;
}

int main() {
    vector<int> piles = inputArrayInt();
    int k;
    cin >> k;
    
    cout << minStoneSum(piles, k);
    
    return 0;
}

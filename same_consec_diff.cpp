#include <iostream>
#include <vector>

using namespace std;

void DFS(int N, int num, int K, vector<int>& results) {
    if (N == 0) {
        results.push_back(num);
        return;
    }
    
    vector<int> nextDigits;
    int tailDigit = num % 10;
    nextDigits.push_back(tailDigit + K);
    if (K != 0) {
        nextDigits.push_back(tailDigit - K);
    }
    
    for (int nextDigit : nextDigits) {
        if (0 <= nextDigit && nextDigit < 10) {
            int newNum = num * 10 + nextDigit;
            DFS(N - 1, newNum, K, results);
        }
    }
}

vector<int> numsSameConsecDiff(int N, int K) {
    vector<int> results;
    
    if (N == 1) {
        for (int i = 0; i <= 9; i++) {
            results.push_back(i);
        }
        return results;
    }
    
    for (int num = 1; num <= 9; num++) {
        DFS(N - 1, num, K, results);
    }
    
    return results;
}

int main() {
    int N, K;
    cin >> N >> K;
    
    vector<int> results = numsSameConsecDiff(N, K);
    
    for (int i = 0; i < results.size(); i++) {
        if (i != results.size() - 1) {
            cout << results[i] << " ";
        } else {
            cout << results[i];
        }
    }
    
    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

vector<string> generateParenthesis(int n) {
    vector<string> ans;
    if (n == 0) {
        ans.push_back("");
    } else {
        for (int c = 0; c < n; ++c) {
            for (string left : generateParenthesis(c)) {
                for (string right : generateParenthesis(n - 1 - c)) {
                    ans.push_back("(" + left + ")" + right);
                }
            }
        }
    }
    return ans;
}

int main() {
    int N;
    cin >> N;
    vector<string> results = generateParenthesis(N);
    int size = results.size();
    for (int i = 0; i < size; i++) {
        if (i != size - 1) {
            cout << results[i] << " ";
        } else {
            cout << results[i];
        }
    }
    return 0;
}

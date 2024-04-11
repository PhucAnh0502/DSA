#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <sstream>

using namespace std;

int minMutation(string start, string end, vector<string>& bank) {
    if (start == end) {
        return 0;
    }

    unordered_set<string> bankSet(bank.begin(), bank.end());
    vector<char> charSet{'A', 'C', 'G', 'T'};

    int level = 0;
    unordered_set<string> visited;
    queue<string> q;
    q.push(start);
    visited.insert(start);

    while (!q.empty()) {
        int size = q.size();

        while (size-- > 0) {
            string curr = q.front();
            q.pop();

            if (curr == end) {
                return level;
            }

            for (int i = 0; i < curr.length(); i++) {
                char old = curr[i];

                for (char c : charSet) {
                    curr[i] = c;
                    string next = curr;

                    if (visited.find(next) == visited.end() && bankSet.find(next) != bankSet.end()) {
                        visited.insert(next);
                        q.push(next);
                    }
                }

                curr[i] = old;
            }
        }

        level++;
    }

    return -1;
}

vector<string> inputArrayString() {
    string line;
    getline(cin, line);
    istringstream iss(line);
    vector<string> result;
    string word;

    while (iss >> word) {
        result.push_back(word);
    }

    return result;
}

int main() {
    string start, end;
    start = inputArrayString()[0];
    end = inputArrayString()[0];
    vector<string> bank = inputArrayString();
    int result = minMutation(start, end, bank);
    cout << result << endl;

    return 0;
}

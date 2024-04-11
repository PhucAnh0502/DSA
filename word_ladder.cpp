#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <sstream>

using namespace std;

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    if (beginWord.empty() || endWord.empty() || beginWord.length() != endWord.length()) {
        return 0;
    }

    unordered_set<string> wordSet(wordList.begin(), wordList.end());
    if (wordSet.find(endWord) == wordSet.end()) {
        return 0;
    }

    queue<string> q;
    int step = 1;
    q.push(beginWord);

    while (!q.empty()) {
        int size = q.size();

        for (int i = 0; i < size; i++) {
            string curr = q.front();
            q.pop();

            for (int j = 0; j < curr.length(); j++) {
                string temp = curr;

                for (char c = 'a'; c <= 'z'; c++) {
                    temp[j] = c;

                    if (temp == endWord) {
                        return step + 1;
                    }

                    if (wordSet.find(temp) != wordSet.end()) {
                        q.push(temp);
                        wordSet.erase(temp);
                    }
                }
            }
        }

        step++;
    }

    return 0;
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
    string beginWord, endWord;
    getline(cin, beginWord);
    getline(cin, endWord);
    vector<string> wordList = inputArrayString();
    int result = ladderLength(beginWord, endWord, wordList);
    cout << result << endl;

    return 0;
}

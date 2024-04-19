#include <iostream>
#include <vector>
using namespace std;

const int ALPHABET_SIZE = 26;

class TrieNode {
public:
    vector<TrieNode*> children;
    bool isEndOfWord;
    
    TrieNode() {
        children = vector<TrieNode*>(ALPHABET_SIZE, nullptr);
        isEndOfWord = false;
    }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string key) {
        TrieNode* pCrawl = root;
        for (char c : key) {
            int index = c - 'a';
            if (pCrawl->children[index] == nullptr) {
                pCrawl->children[index] = new TrieNode();
            }
            pCrawl = pCrawl->children[index];
        }
        pCrawl->isEndOfWord = true;
    }
    
    bool search(string key) {
        TrieNode* pCrawl = root;
        for (char c : key) {
            int index = c - 'a';
            if (pCrawl->children[index] == nullptr) {
                return false;
            }
            pCrawl = pCrawl->children[index];
        }
        return pCrawl != nullptr && pCrawl->isEndOfWord;
    }
};

vector<string> inputArrayString() {
    string text;
    getline(cin, text);
    vector<string> result;
    size_t pos = 0;
    while ((pos = text.find(' ')) != string::npos) {
        result.push_back(text.substr(0, pos));
        text.erase(0, pos + 1);
    }
    result.push_back(text);
    return result;
}

int main() {
    vector<string> keys = inputArrayString();
    vector<string> searchs = inputArrayString();
    
    Trie trie;
    for (const string& key : keys) {
        trie.insert(key);
    }
    
    for (size_t i = 0; i < searchs.size() - 1; i++) {
        if (trie.search(searchs[i])) {
            cout << "true ";
        } else {
            cout << "false ";
        }
    }
    
    if (trie.search(searchs.back())) {
        cout << "true";
    } else {
        cout << "false";
    }
    
    return 0;
}

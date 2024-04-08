#include <bits/stdc++.h>
using namespace std;

#define INF 10000
vector<int> ans;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

TreeNode* makeTree(vector<string>& node) {
    if (node.empty() || node[0] == "null") {
        return nullptr;
    }
    queue<TreeNode*> q;
    TreeNode* root = new TreeNode(stoi(node[0]));
    q.push(root);
    int i = 1;
    while (!q.empty() && i < node.size()) {
        TreeNode* curr = q.front();
        q.pop();
        if (node[i] != "null") {
            curr->left = new TreeNode(stoi(node[i]));
            q.push(curr->left);
        }
        i++;
        if (i < node.size() && node[i] != "null") {
            curr->right = new TreeNode(stoi(node[i]));
            q.push(curr->right);
        }
        i++;
    }
    return root;
}
int size_tree(TreeNode*root){
  if(root==NULL) return 0;
  int cnt=1;
  cnt+=size_tree(root->right);
  cnt+=size_tree(root->left);
  return cnt;
}

void printGivenLevel(TreeNode* root, int level, bool ltr) {
    if(root == NULL) return;
    if(level == 1){
        ans.push_back(root->val);
    } else if(level > 1){
        if(ltr){
            printGivenLevel(root->right, level-1, ltr);
            printGivenLevel(root->left, level-1, ltr);
        } else{
            printGivenLevel(root->left, level-1, ltr);
            printGivenLevel(root->right, level-1, ltr);
        }
    }
}
int height(TreeNode*root){
  if(root==nullptr) return 0;
  else{
    return max(height(root->left),height(root->right))+1;
  }
}
void printSpiral(TreeNode* root) {
    int h = height(root);
    bool ltr = false;
    for(int i = 1; i <= h; i++){
        // In theo tung level
        printGivenLevel(root, i, ltr);
        ltr = !ltr;
    }
}
int main() {
    string s;
    getline(cin, s);
    stringstream ss(s);
    string s1;
    vector<string> node;
    while (ss >> s1) {
        node.push_back(s1);
    }
    TreeNode* root = makeTree(node);
    printSpiral(root);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i];
        if(i!=ans.size()-1){
            cout<<" ";
        }
    }
    return 0;
}


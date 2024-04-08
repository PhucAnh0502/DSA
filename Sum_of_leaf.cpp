 #include <bits/stdc++.h>
using namespace std;

#define INF 10000

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
int height(TreeNode*node)
{
    if(node==NULL) return 0;
    else{
        return max(height(node->left),height(node->right))+1;
    }
}
int sum_of_Level(TreeNode*node,int level)
{
    int sum=0;
    if(node==nullptr) return 0;
    if(level==1){
        sum=node->val;
    }else if(level>1){
        sum+=sum_of_Level(node->left,level-1);
        sum+=sum_of_Level(node->right,level-1);
    }
    return sum;
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
    cout<<sum_of_Level(root,height(root));
    return 0;
}

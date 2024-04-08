#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <math.h>
#include <queue>
#include <limits>

using namespace std;

struct tree_node {
  int data;
  tree_node* left;
  tree_node* right;
  
  tree_node() : data(0), left(NULL), right(NULL) {}
  
  static tree_node* create(int value) {
    tree_node* newnode = new tree_node;
    newnode->data  = value;
    newnode->left  = nullptr;
    newnode->right = nullptr;
    return newnode;
  }
};

class binary_tree {
private:
  using node    = tree_node;
  using nodeptr = node*;
  
  nodeptr _Myroot;
  
  void _Construct(vector<string> input) {
    queue<nodeptr*> Q;
    _Myroot = nullptr;
    
    Q.push(&_Myroot);
    
    for(string strval : input) {
      if(strval != "null") {
        *Q.front() = node::create(stoi(strval));
        Q.push(&(*Q.front())->left);
        Q.push(&(*Q.front())->right);
      }
      
      Q.pop();
    }
  }
  
  void _Print_tree(nodeptr root) {
    if(root != nullptr) {
      cout << root->data << " ";
      _Print_tree(root->left);
      _Print_tree(root->right);
    }
  }
  
  void _Erase_tree(nodeptr root) {
    if(root != nullptr) {
      _Erase_tree(root->left);
      _Erase_tree(root->right);
      delete root;
    }
  }
  
  int _Max_diff_sub(nodeptr root, int ancestor) {
    if(root != nullptr) {
      return max(
        max(abs(ancestor - root->data), _Max_diff_sub(root->left, ancestor)),  
        max(abs(ancestor - root->data), _Max_diff_sub(root->right, ancestor))
      );
    } 
    
    return 0;
  }
  
  int _Max_diff(nodeptr root) {
    if(root == nullptr) 
      return 0;
    
    int curr_max = max(
      _Max_diff_sub(root->left, root->data), 
      _Max_diff_sub(root->right, root->data)
    );
    
    return max(
      max(curr_max, _Max_diff(root->left)),
      max(curr_max, _Max_diff(root->right))
    );
  }
  
public:
  binary_tree() : _Myroot(nullptr) {}
  
  binary_tree(vector<string> input) {
    _Construct(input);
  }
  
  void print() {
    _Print_tree(_Myroot);
  }
  
  int max_difference() {
    return _Max_diff(_Myroot);
  }
  
  ~binary_tree() {
    _Erase_tree(_Myroot);
  }
};


int main() {
  string str = "";
  getline(cin, str);
  
  istringstream strIn(str);
  vector<string> input;
  
  while(strIn >> str) {
    input.push_back(str);
  }
  
  binary_tree _Mytree(input);
  
  cout << _Mytree.max_difference();
  
  return 0;
}

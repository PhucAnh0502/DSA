#include<bits/stdc++.h>

using namespace std;

struct Node{
  int data;
  Node *next;
};

Node* create(int x){
  Node *tmp = new Node;
  tmp->data = x;
  tmp->next = NULL;
  return tmp;
}

Node* addNode(Node *p, int x){
  Node *tmp = create(x);
  p->next = tmp;
  return tmp;
}

void deleteNode(Node *&head){
  Node *s = head;
  while(s!=NULL){
    Node *f = s;
    while(f->next!=NULL){
      if(s->data==f->next->data){
        Node *tmp = f->next;
        f->next = f->next->next;
        delete(tmp);
      }
      else{
        f=f->next;
      }
    }
    s=s->next;
  }
}

void print(Node *head){
  Node *p = head;
  while(p!=NULL){
    cout << p->data;
    if(p->next == NULL) return;
    cout << " ";
    p = p->next;
  }
}

int main(){
  string s;
  getline(cin, s);
  stringstream ss(s);
  vector<int> a;
  int b;
  while(ss>>b){
    a.push_back(b);
  }
  Node *head = NULL;
  Node *p = NULL;
  for(int i=0;i<a.size();i++){
    if(i==0){
      p = create(a[i]);
      head = p;
    }
    else {
      p = addNode(p,a[i]);
    }
  }
  deleteNode(head);
  print(head);
}

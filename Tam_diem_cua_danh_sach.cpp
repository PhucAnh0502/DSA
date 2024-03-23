#include <bits/stdc++.h>
using namespace std;
 
struct Node{
int data;
Node* next;
};
 
Node* createNode(int x){
Node* tmp=new Node;
tmp->data=x;
tmp->next=NULL;
return tmp;
}
 
Node* addNode(Node* p,int x){
Node* tmp=createNode(x);
p->next=tmp;
return tmp;
}
void checkMiddle(Node* head){
Node* f=head;
Node* s=head;
while(f->next!=NULL&&f->next->next!=NULL){
s=s->next;
f=f->next->next;
}
if(f->next==NULL){
cout<<s->data;
return;
}
if(f->next->next==NULL){
cout<<s->data<<" "<<s->next->data;
return;
}
}
int main(){
string s;
getline(cin,s);
stringstream ss(s);
vector<int> a;
int b;
while(ss>>b){
a.push_back(b);
}
Node* head=NULL;
Node* p=NULL;
for(int i=0;i<a.size();i++){
if(i==0){
p=createNode(a[i]);
head=p;
} else{
p=addNode(p,a[i]);
}
}
checkMiddle(head);
}

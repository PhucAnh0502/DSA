#include<bits/stdc++.h>
#include<list>
using namespace std;

//Khai bao
struct DNode{
	int val;
	DNode* prev;
	DNode* next;
};

DNode* first;
DNode* last;

//Tao moi ptu
DNode* makeNode(int v){
	DNode* p = new DNode;
	p->val = v;
	p->next = NULL;
	p->prev = NULL;
	return p;
}

//Xoa ptu
void remove(DNode* p){
	if(p == NULL) return;
	if(first == last && p == first){
		first = NULL;
		last = NULL;
		delete p;
	}
	if(p == first){
		first = p->next;
		first->prev = NULL;
		delete p;
		return;
	}
	if(p == last){
		last = p->prev;
		last->next = NULL;
		delete p;
		return;
	}
	p->prev->next = p->next;
	p->next->prev = p->prev;
	delete p;
}

//Them ptu vao cuoi
void insertLast(int x){
	DNode* q = makeNode(x);
	if(first == NULL && last == NULL){
		first = q;
		last = q;
		return;
	}
	q->prev = last;
	last->next = q;
	last = q;
}

int main(){
	list<int> L;
	for(int i=1;i<=10;i++){
		L.push_back(i);
	}
	list<int>::iterator it;
	for(it = L.begin();it != L.end(); it++ ){
		int x = *it;
		printf("%d ",x); 
	}
	return 0;
}

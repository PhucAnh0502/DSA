#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//khai bao
struct Node{
	int value;
	Node* next;
};
Node* head; 

//Tim kiem
void printList(Node* h){ // In ra danh sach
	Node* p = h;
	while(p!=NULL){
		printf("%d", p->value);
		p=p->next;
	}
}

Node* findLast(Node* h){ //Tim phan tu cuoi cung
	Node* p = h;
	while(p != NULL){
		if(p->next==NULL) return p;
		p = p->next
	}
	return NULL;
}

//Chen phan tu x vao sau phan tu tro boi p
Node* makeNode(int x){
	Node* q = new Node;
	q->value = x;
	q->next = NULL;
	return q;
}

Node* insertAfter(Node* h, Node* p, int x){
	if(p == NULL) return h;
	Node* q = makeNode(x);
	if(h == NULL) return q;
	q->next=p->next;
	p->next = q;
	return h;
}

//Chen mot phan tu x vao cuoi danh sach
Node* insertLast(Node* h, int x){
	Node* q = makeNode(x);
	if(h == NULL) return q;
	while(p->next != NULL) p = p->next;
	p->next = q;
	return h;
}

//Tim phan tu dau tien co value = x ke tu trai sang
Node* locate(Node* h, int x){
	Node* p = h;
	while(p != NULL){
		if(p->value == x) return p;
		p=p->next
	}
	return NULL;
}

//Tim ptu dung truoc ptu dc tro boi con tro p
Node* prev(Node* h, NOde* p){
	Node* q = h;
	while(q != NULL){
		if(q->next == p) return q;
		q = q->next
	}
	return NULL;
}

//Chen ptu x vao truoc ptu tro boi p
Node* insertAt(Node* h, Node* p, int x){
	Node* pp = prev(h,p);
	if(pp == NULL && p!=NULL) return h;
	Node* q = new Node;
	q->value = x;
	q->next = NULL;
	if(pp == NULL){
		if(h == NULL) return q;
		q->next = h;
		return q;
	}
	q->next=p;
	pp->next=q;
	return h;
}

Node* insertAtRecursive(Node* h, Node* p, int x){ //Dung de quy
	if(p == NULL) return h;
	if(h == NULL) return makeNode(x);
	else{
		h->next = insertAtRecursive(h->next,p,x);
		return h;
	}
}

//Xoa ptu tro boi p
Node* remove(Node* h, Node* p){
	if(h==NULL||p==NULL) return h;
	if(h==p){
		h = h->next;
		delete p;
		return h;
	}
	else{
		h->next = remove(h->next,p);
		return h;
	}
}

//Tong cac ptu trong danh sach
Node* sumRecursive(Node* h){ //Dung de quy
	if(h==NULL) return 0;
	return h->value + sumRecursive(h->next);
}

Node* sum(Node* h){
	Node* p = h; 
	int s = 0;
	while(p!=NULL){
		s=s+p->value;
		p=p->next;
	}
	return s;
}

int main(){
	return 0;
}

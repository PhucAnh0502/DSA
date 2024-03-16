#include<stdio.h>
#include<stdlib.h>

//CAY
struct Node{
	int id;
	Node* leftMostChild; //con tro tro den nut trai nhat
	Node* rightSibling; // con tro tro den nut ae ben phai
};
Node* root; //con tro tro den nut goc

Node* find(Node* r, int v){ //Tim nut co nhan v
	if(r==NULL) return NULL;
	if(r->id==v) return r;
	Node* p = r->leftMostChild;
	while(p!=NULL){
		Node* h = find(p,v);
		if(h != NULL) return h;
		p = p->rightSibling;
	}
	return NULL
}

void preOrder(Node* r){ //Duyet theo thu tu truoc
	if(r==NULL) return;
	printf("%d ",r->id);
	Node *p = r->leftMostChild;
	while(p!=NULL){
		preOrder(p);
		p = p->rightSibling;
	}
}

void inOrder(Node* r){ //Duyet theo thu tu giua
	if(r==NULL) return;
	Node* p = r->leftMostChild;
	inOrder(p);
	printf("%d ",r->id);
	if(p!=NULL){
		p = p->rightSibling;
	}
	while(p!=NULL){
		inOrder(p);
		p = p->rightSibling;
	}
}

void postOrder(Node* r){ //Duyet theo thu tu sau
	if(r==NULL) return;
	Node* p = r->leftMostChild;
	while(p!=NULL){
		postOrder(p);
		p = p->rightSibling;
	}
	printf("%d ",r->id)
}

int count(Node* r){ //Dem so nut tren cay
	if(r==NULL) return 0;
	int s = 1;
	Node* p = r->leftMostChild;
	while(p!=NULL){
		s += count(p);
		p = p->rightSibling;
	}
	return s;
}

int countLeaves(Node* r){ //Dem so nut la
	if(r==NULL) return 0;
	int s = 0;
	Node* p = r->leftMostChild;
	if(p==NULL) s = 1;
	while(p!=NULL) {
		s+=countLeaves(p);
		p = p->rightSibling;
	}
	return s;
}

int height(Node* p){ //Do cao cua mot nut
	if(p == NULL) return 0;
	int maxh = 0;
	Node* q = p->leftMostChild;
	while(q!=NULL){
		int h = height(q);
		if(h > maxh) maxh = h;
		q = q->rightSibling;
	}
	return maxh + 1;
}

int depth(Node* r, int v, int d){ //Do sau cua 1 nut
	//d la do sau cua nut r
	if(r==NULL) return -1;
	if(r->id==v) return d;
	Node* p = r->leftMostChild;
	while(p!=NULL){
		if(p->id==v) return d+1;
		int dv = depth(p,v,d+1);
		if(dv>0) return dv;
		p = p->rightSibling;
	}
	return -1;
}
int depth(Node* r,int v){
	return depth(r,v,1);
}

Node *parent(Node* p, Node* r){ //Tim nut cha cua 1 nut
	if(r==NULL) return NULL;
	Node *q = r->leftMostChild;
	while(q!=NULL){
		if(p==q) return r;
		Node* pp = parent(p,q);
		q = q->rightSibling;
	}
	return NULL;
}

//CAY NHI PHAN
struct BNode{
	int id;
	BNode* leftChild;
	BNode* rightChild;
};

void inOrder2(BNode* r){ //Duyet theo thu tu giua
	if(r==NULL) return;
	inOrder(r->leftChild);
	printf("%d ",r->id);
	inOrder(r->rightChild);
}

void preOrder2(BNode* r){ //Duyet theo thu tu truoc
	if(r==NULL) return;
	printf("%d ",r->id);
	preOrder(r->leftChild);
	preOrder(r->rightChild);
}

void postOrder2(BNode* r){ //Duyet theo thu tu sau
	if(r==NULL) return;
	postOrder(r->leftChild);
	postOrder(r->rightChild);
	printf("%d ",r->id);
}

int count2(BNode* r){ //Dem so nut
	if(r==NULL) return 0;
	return 1 + count2(r->leftChild) + count2(r->rightChild);
}


#include<bits/stdc++.h>

using namespace std;

struct State{
	int x;
	int y;
	char* msg; // action to generate current state
	State* p; //pointer to the state generating the current state
};

bool visited[10000][10000];
queue<State*> Q;
list<State*> L;
State* target;
int a,b,c;

void initVisited(){
	for(int i=0;i<10000;i++){
		for(int j=0;j<10000;j++){
			visited[i][j] = false;
		}
	}
}

bool reachTarget(State* S){
	return S->x == c|| S->y == c|| S->x+S->y == c;
}

void markVisit(State* S){
	visited[S->x][S->y] = true;
}

void freeMemory(){
	list<State*>::iterator it;
	for(it=L.begin();it!=L.end();it++){
		delete *it;
	}
}

bool genMove1Out(State* S){ //Do het nuoc tu coc 1 ra ngoai
	if(visited[0][S->y]) return false;
	State* newS = new State;
	newS->x = 0;
	newS->y = S->y;
	newS->msg = "Do het nuoc o coc 1 ra ngoai";
	newS->p = S;
	Q.push(newS); markVisit(newS);
	L.push_back(newS);
	if(reachTarget(newS)){
		target = newS;
		return true;
	}
	return false;
}

bool genMove2Out(State* S){ //Do het nuoc tu coc 2 ra ngoai
	if(visited[S->x][0]) return false;
	State* newS = new State;
	newS->x = S->x;
	newS->y = 0;
	newS->msg = "Do het nuoc o coc 2 ra ngoai";
	newS->p = S;
	Q.push(newS); markVisit(newS);
	L.push_back(newS);
	if(reachTarget(newS)){
		target = newS;
		return true;
	}
	return false;
}

bool genMove1Full2(State* S){ //Do nuoc tu coc 1 vao day coc 2
	if(S->x+S->y < b) return false;
	if(visited[S->x + S->y - b][b]) return false;
	State* newS = new State;
	newS->x = S->x + S->y - b;
	newS->y = b;
	newS->msg = "Do nuoc tu coc 1 vao day coc 2";
	newS->p = S;
	Q.push(newS); markVisit(newS);
	L.push_back(newS);
	if(reachTarget(newS)){
		target = newS;
		return true;
	}
	return false;
}

bool genMove2Full1(State* S){ //Do nuoc tu coc 2 vao day coc 1
	if(S->x+S->y < a) return false;
	if(visited[a][S->x + S->y - a]) return false;
	State* newS = new State;
	newS->x = a;
	newS->y = S->x + S->y - a;
	newS->msg = "Do nuoc tu coc 2 vao day coc 1";
	newS->p = S;
	Q.push(newS); markVisit(newS);
	L.push_back(newS);
	if(reachTarget(newS)){
		target = newS;
		return true;
	}
	return false;
}

bool genMoveAll12(State* S){ //Do het nuoc tu coc 1 sang coc 2
	if(S->x + S->y > b) return false;
	if(visited[0][S->x + S->y]) return false;
	State* newS = new State;
	newS->x = 0;
	newS->y = S->x + S->y;
	newS->msg = "Do het nuoc tu coc 1 sang coc 2";
	newS->p = S;
	Q.push(newS); markVisit(newS);
	L.push_back(newS);
	if(reachTarget(newS)){
		target = newS;
		return true;
	}
	return false;
}

bool genMoveAll21(State* S){ //Do het nuoc tu coc 2 sang coc 1
	if(S->x + S->y > a ) return false;
	if(visited[S->x + S->y][0]) return false;
	State* newS = new State;
	newS->x = S->x + S->y;
	newS->y = 0;
	newS->msg = "Do het nuoc tu coc 2 sang coc 1";
	newS->p = S;
	Q.push(newS); markVisit(newS);
	L.push_back(newS);
	if(reachTarget(newS)){
		target = newS;
		return true;
	}
	return false;
}

bool genMoveFill1(State* S){ //Do day nuoc tu be vao coc 1
	if(visited[a][S->y]) return false;
	State* newS = new State;
	newS->x = a;
	newS->y = S->y;
	newS->msg = "Do day nuoc vao coc 1";
	newS->p = S;
	Q.push(newS); markVisit(newS);
	L.push_back(newS);
	if(reachTarget(newS)){
		target = newS;
		return true;
	}
	return false;
}

bool genMoveFill2(State* S){ //Do day nuoc tu be vao coc 2
	if(visited[S->x][b]) return false;
	State* newS = new State;
	newS->x = S->x;
	newS->y = b;
	newS->msg = "Do day nuoc vao coc 2";
	newS->p = S;
	Q.push(newS); markVisit(newS);
	L.push_back(newS);
	if(reachTarget(newS)){
		target = newS;
		return true;
	}
	return false;
}

void print(State* target){ //In ra kq
	cout << "-----------RESULT-----------" << endl;
	if(target==NULL){
		cout << "NO SOLUTION!" << endl;
	}
	State* currentS = target;
	stack<State*> actions;
	while(currentS != NULL){
		actions.push(currentS);
		currentS = currentS->p;
	}
	while(actions.size() > 0){
		currentS = actions.top();
		actions.pop();
		printf("%s, (%d,%d)\n",currentS->msg,currentS->x,currentS->y);
	}
}

void solve(){
	initVisited();
	State* S = new State;
	S->x = 0; S->y = 0; S->p = NULL;
	Q.push(S); markVisit(S);
	while(!Q.empty()){
		State* S = Q.front(); Q.pop();
		if(genMove1Out(S)) break;
		if(genMove2Out(S)) break;
		if(genMove1Full2(S)) break;
		if(genMoveAll12(S)) break;
		if(genMove2Full1(S)) break;
		if(genMoveAll21(S)) break;
		if(genMoveFill1(S)) break;
		if(genMoveFill2(S)) break;
	}
}

int main(){
	cin >> a >> b >> c;
	target = NULL;
	solve();
	print(target);
	freeMemory();
}

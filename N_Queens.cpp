#include <bits/stdc++.h>

using namespace std;

int N, x[100], cot[100], duong_cheo_xuoi[100], duong_cheo_nguoc[100];
int a[100][100];

void print(){
	memset(a,0,sizeof(a));
	for(int i=1;i<=N;i++){
		a[i][x[i]] = 1;
	}
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void Try(int j){
	//Duyet cac kha nang ma x[i] co the nhan duoc
	for(int i=1;i<=N;i++){
		//Kiem tra truoc khi gan x[i]=j
		if(cot[j]==1&&duong_cheo_xuoi[i-j+N]==1&&duong_cheo_nguoc[i+j-1]==1){
			x[i] = j;
			cot[j] = duong_cheo_xuoi[i-j+N] = duong_cheo_nguoc[i+j-1] = 0;
			if(i==N) print();
			else Try(i+1);
			//backtrack
			cot[j] = duong_cheo_xuoi[i-j+N] = duong_cheo_nguoc[i+j-1] = 1;
		}
	}
}

int main(){
	cin >> N;
	for(int i=1;i<=99;i++){
		cot[i] = duong_cheo_xuoi[i] = duong_cheo_nguoc[i] = 1;
	}
	Try(1);
	return 0;
}

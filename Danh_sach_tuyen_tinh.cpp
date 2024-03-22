#include<bits/stdc++.h>

using namespace std;

int a[100000], n;

void insert(int x, int p){ //Them 1 ptu vao danh sach
	for(int i=n-1;i>=p;i--) a[i+1]=a[i];
	a[p] = x;
	n=n+1;
}

void delete(int p){ //Xoa 1 ptu khoi danh sach
	for(int i=p+1;i<n;i++) a[i - 1] = a[i];
	n = n - 1;
	
}

int retrieve (int p){ //Tra ve gia tri ptu tai vi tri p
	return a[p];
}

int locate(int x){ //Vi tri dau tien cua x trong danh sach
	for(int i=0;i<n;i++){
		if(a[i]==x) return i;
	}
	return -1;
}

void makenull(){
	n=0;
}

int next(int p){ //Vi tri sau vtri p
	if(0 <= p && p < n - 1) return p + 1;
	return -1
}

int prev(int p){
	if(p>0&&p<= n - 1) return p - 1;
	return -1;
}

int main(){
	cin >> n;
	for(int i-0;i<n;i++){
		cin >> a[i];
	}
}

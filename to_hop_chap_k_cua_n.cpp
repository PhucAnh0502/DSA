#include <bits/stdc++.h>

using namespace std;

int n,k,a[1000];
void Print(){
	for(int i=1;i<=k;i++){
		cout << a[i];
	}
	cout << endl;
}
int Try(int i){
	for(int v=a[i-1]+1;v<=n - k + i;v++){
		a[i] = v;
		if(i==k) Print();
		else Try(i+1);
	}
}
int main(){
	cin >> n >> k;
	a[0]=0;
	Try(1);
}

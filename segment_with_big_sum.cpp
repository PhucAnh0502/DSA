#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
	ll n,s;
	cin >> n >> s;
	int a[n];
	for(int i=0;i<n;i++) cin >> a[i];
	int l=0,r;
	ll sum = 0;
	int ans = 1e9;
	for(r=0; r<n;r++){
		sum+=a[r];
		while(sum >= s){
			ans=min(ans,r - l + 1);
			sum -= a[l];
			++l;
		}
	}
	if(ans == 1e9) cout << "-1";
	else cout << ans << endl;
}

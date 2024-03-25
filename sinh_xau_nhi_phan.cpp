//Sinh 1 xau nhi phan co k phan tu trong do khong co 2 phan tu 1 dung lien ke nhau
#include<bits/stdc++.h>

using namespace std;
long long k,ok;
long long a[10000];

void ktao(){
  for(int i=1;i<=k;i++) a[i]=0;
}

void sinh(){
  int i=k;
  while(i>=1&&a[i]==1){
    a[i]=0;
    --i;
  }
  if(i==0) ok=0;
  else a[i]=1;
}

bool check(){
  for(int i=1;i<=k;i++){
    if(a[i]==1&&a[i+1]==1){
      return false;
    }
  }
  return true;
}

int main(){
  cin >> k;
  ok=1;
  while(ok){
    if(check()){
      for(int i=1;i<=k;i++){
        cout << a[i];
      }
      cout << " ";
    }
    sinh();
  }
  return 0;
}

#include<bits/stdc++.h>

using namespace std;

void chuyen(long long n, char a, char b){
  cout << "Disk" << " " << n << " moved from " << a << " to " << b << endl ;
}

void tower(long long n, char a, char b, char c){
  if(n==1) chuyen(1,a,c);
  else {
    tower(n - 1,a,c,b);
    chuyen(n,a,c);
    tower(n - 1,b,a,c);
  }
}

int main(){
  long long n;
  cin >> n;
  char a ='A';
  char b ='B';
  char c ='C';
  tower(n,a,b,c);
}

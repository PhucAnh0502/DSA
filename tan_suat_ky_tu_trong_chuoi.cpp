#include<bits/stdc++.h>

using namespace std;

int main(){
  string s;
  getline(cin,s);
  map<char,int> ts;
  for(int i=0;i<s.length();i++){
    ts[s[i]]++;
  }
  for(int i=0;i<s.length();i++){
    if(ts[s[i]]!=0){
      cout << s[i] << ts[s[i]] << " ";
      ts[s[i]] = 0;
    }
  }
}

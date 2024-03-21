#include<bits/stdc++.h>

using namespace std;

int main(){
  string result;
  string s;
  getline(cin,s);
  stringstream ss(s);
  string tmp;
  while(ss >> tmp){
    result += tmp + ' '; 
  }
  result.pop_back();
  cout << result;
}

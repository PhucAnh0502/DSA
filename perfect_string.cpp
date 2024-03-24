#include<bits/stdc++.h>
using namespace std;

//check 2 ki tu lien ke
bool check(char s1, char s2){
  return tolower(s1) == tolower(s2) && s1!=s2;
}

string solve(string s){
  string ans = "";
  for(char x : s){
    if(!ans.empty()&&check(x,ans.back())){
      ans.pop_back();
    }
    else ans.push_back(x);
  }
  return ans;
}

int main(){
  string s; cin >> s;
  cout << solve(s) << endl;
  return 0;
}

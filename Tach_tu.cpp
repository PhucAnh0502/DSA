#include<bits/stdc++.h>

//Tach cac tu quen khong cho dau cach: HocThuatToanThatVui -> hoc thuat toan that vui

using namespace std;
string tach(string s){
  string result = "";
  for(int i=0;i<s.length();i++){
    if(s[i]>='A'&&s[i]<='Z') result = result + " " + char(s[i] + 32);
    else result = result + s[i];
  }
  return result;
}
int main(){
  string s;
  cin >> s;
  cout << "Ket qua tach tu:" << tach(s);
  return 0;
}

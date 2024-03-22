//Dem day bit 1 dai nhat voi k lan doi bit 0 thanh bit 1
//Input
//1 1 1 0 0 0 1 1 1 1 0
//2
//Output
//6
#include<bits/stdc++.h>

using namespace std;

int longest(vector<int> nums, int k){
  int l=0,r=0;
  int ans=0;
  int cnt=0;
  while(r<nums.size()){
    if(nums[r]==0) cnt++;
    while(cnt>k){
      if(nums[l]==0) cnt--;
      l++;
    }
    ans=max(ans,r - l + 1);
    r++;
  }
  return ans;
}

int main(){
  string ip;
  getline(cin,ip);
  stringstream ss(ip);
  int number;
  vector<int> nums;
  while(ss>>number) nums.push_back(number);
  int k; cin>>k;
  cout << longest(nums,k);
}

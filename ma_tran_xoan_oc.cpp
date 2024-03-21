#include<bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin>> n;
  int a[n][n];
  int minrow=0;
  int maxrow=n - 1;
  int mincol=0;
  int maxcol=n - 1;
  int value=1;
  while(value <= n*n){
    //Trai sang phai
    for(int i=mincol;i<=maxcol;i++){
      a[minrow][i] = value++;
    }
    minrow++;
    //Tren xuong duoi
    for(int i=minrow;i<=maxrow;i++){
      a[i][maxcol] = value++;
    }
    maxcol--;
    //Phai sang trai
    for(int i=maxcol;i>=mincol;i--){
      a[maxrow][i] = value++;
    }
    maxrow--;
    //Duoi len tren
    for(int i=maxrow;i>=minrow;i--){
      a[i][mincol] = value++;
    }
    mincol++;
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cout << a[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}

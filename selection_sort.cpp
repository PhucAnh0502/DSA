#include<stdio.h>

void selectionSort(int a[], int n){
	for(int k = 0;k<n;k++){
		int min = k;
		for(int j = k+1;j<n;j++){
			if(a[min]>a[j]) min = j;
		}
		int tmp = a[min];
		a[min] = a[k];
		a[k] = tmp;
	}
}

int main(){
  int n;
  scanf("%d", &n);
  int a[n];
  for(int i = 0;i<n;i++){
    scanf("%d", &a[i]);
  }
  selectionSort(a,n);
  for(int i = 0;i<n;i++){
    printf("%d ",a[i]);
  }
}


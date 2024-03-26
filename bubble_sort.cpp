#include<stdio.h>


void sort(int arr[], int size) {
  for (int step = 0; step < size - 1; ++step) {
    int swapped = 0;
    for (int i = 0; i < size - step - 1; ++i) {
      if (arr[i] > arr[i + 1]) {
        int temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
        swapped = 1;
      }
    }
    if (swapped == 0)
      break;
  }
}

int main(){
  int n;
  scanf("%d",&n);
  int a[n];
  for(int i = 0;i<n;i++){
    scanf("%d",&a[i]);
  }
  sort(a,n);
  for(int i = 0;i<n;i++){
    printf("%d ",a[i]);
  }
}

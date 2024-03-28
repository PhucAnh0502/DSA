#include <stdio.h>

int get_max_element(int arr[], int n) {
  int max = arr[0];
  for (int i = 1; i < n; i++)
    if (arr[i] > max)
      max = arr[i];
  return max;
}

void sort_counting(int arr[], int size, int place) {
  int output[size + 1];
  int max = (arr[0] / place) % 10;

  for (int i = 1; i < size; i++) {
    if (((arr[i] / place) % 10) > max)
      max = arr[i];
  }
  int count[max + 1];

  for (int i = 0; i < max; ++i)
    count[i] = 0;

  for (int i = 0; i < size; i++)
    count[(arr[i] / place) % 10]++;
    
  for (int i = 1; i < 10; i++)
    count[i] += count[i - 1];

  for (int i = size - 1; i >= 0; i--) {
    output[count[(arr[i] / place) % 10] - 1] = arr[i];
    count[(arr[i] / place) % 10]--;
  }

  for (int i = 0; i < size; i++)
    arr[i] = output[i];
}

void sort_radix(int arr[], int size) {
  int max = get_max_element(arr, size);
  for (int place = 1; max / place > 0; place *= 10)
    sort_counting(arr, size, place);
}

void print(int arr[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d ", arr[i]);
  }
}

int main() {
  int n;
  scanf("%d",&n);
  int arr[n] ;
  for(int i=0;i<n;i++){
    scanf("%d",&arr[i]);
  }
  sort_radix(arr, n);
  print(arr, n);
}

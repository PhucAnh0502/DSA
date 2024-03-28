#include <stdio.h>
#include <stdlib.h>

void Shell_Sort(int arr[], int n);
void print_array(int arr[], int n);

void Shell_Sort(int arr[], int n) {
  if (n <= 0)
    return;

  int gap, i, j, temp;
  for (gap = n / 2; gap > 0; gap /= 2) {
    for (i = gap; i < n; i++) {
      temp = arr[i];
      for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
        arr[j] = arr[j - gap];
      }
      arr[j] = temp;
    }
  }
}

void print_array(int arr[], int n) {
  if (n <= 0)
    return;

  int i;
  for (i = 0; i < n; ++i) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main(void) {
  int n;
  scanf("%d", &n);

  if (n <= 0) {
    return 0;
  }

  int *array = (int *)malloc(sizeof(int) * n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &array[i]);
  }

  Shell_Sort(array, n);

  print_array(array, n);

  free(array);

  return 0;
}

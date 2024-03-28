#include <stdio.h>
#include <stdlib.h>

#define NUMBER_BUCKET 100001

struct Node {
  int data;
  struct Node *next;
};

void Bucket_Sort(int arr[], int n);
struct Node *Insertion_Sort(struct Node *list);
void print_array(int arr[], int n);
void print_bucket(struct Node *list);
int get_bucket_index(int value);

void Bucket_Sort(int arr[], int n) {
  if (n <= 0)
    return;

  int i;
  struct Node **buckets;
  buckets = (struct Node **)malloc(sizeof(struct Node *) * NUMBER_BUCKET);

  for (i = 0; i < NUMBER_BUCKET; ++i) {
    buckets[i] = NULL;
  }

  // Ðua các ph?n t? vào các bucket
  for (i = 0; i < n; ++i) {
    struct Node *current;
    int pos = get_bucket_index(arr[i]);
    current = (struct Node *)malloc(sizeof(struct Node));
    current->data = arr[i];
    current->next = buckets[pos];
    buckets[pos] = current;
  }

  // S?p x?p các bucket b?ng Insertion Sort
  for (i = 0; i < NUMBER_BUCKET; ++i) {
    buckets[i] = Insertion_Sort(buckets[i]);
  }

  // G?p các bucket dã s?p x?p thành dãy s? k?t qu?
  int index = 0;
  for (i = 0; i < NUMBER_BUCKET; ++i) {
    struct Node *node = buckets[i];
    while (node) {
      arr[index++] = node->data;
      node = node->next;
    }
  }

  // Gi?i phóng b? nh? dã c?p phát cho các bucket
  for (i = 0; i < NUMBER_BUCKET; ++i) {
    struct Node *node = buckets[i];
    while (node) {
      struct Node *temp = node;
      node = node->next;
      free(temp);
    }
  }
  free(buckets);
}

// S?p x?p Insertion Sort cho m?t bucket
struct Node *Insertion_Sort(struct Node *list) {
  if (list == NULL || list->next == NULL) {
    return list;
  }

  struct Node *sorted_list = NULL;
  struct Node *current = list;

  while (current != NULL) {
    struct Node *next = current->next;
    
    if (sorted_list == NULL || current->data < sorted_list->data) {
      current->next = sorted_list;
      sorted_list = current;
    } else {
      struct Node *temp = sorted_list;
      while (temp->next != NULL && current->data >= temp->next->data) {
        temp = temp->next;
      }
      current->next = temp->next;
      temp->next = current;
    }

    current = next;
  }

  return sorted_list;
}

// L?y ch? s? bucket cho m?t giá tr?
int get_bucket_index(int value) {
  return value / NUMBER_BUCKET;
}

// In ra m?t m?ng
void print_array(int arr[], int n) {
  if (n <= 0)
    return;

  int i;
  for (i = 0; i < n; ++i) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

// In ra n?i dung c?a m?t bucket
void print_bucket(struct Node *list) {
  struct Node *current = list;
  while (current) {
    printf("%d ", current->data);
    current = current->next;
  }
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

  Bucket_Sort(array, n);

  print_array(array, n);

  free(array);

  return 0;
}

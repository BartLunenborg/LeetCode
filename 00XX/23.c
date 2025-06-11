#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list from description.
struct ListNode {
  int val;
  struct ListNode *next;
};

typedef struct {
  struct ListNode **values;
  int size;
  int max_size;
} Heap;

Heap *new_heap(int len) {
  Heap *heap = malloc(sizeof(Heap));
  heap->max_size = len;
  heap->size = 0;
  heap->values = calloc(len, sizeof(struct ListNode *));
  return heap;
}

void free_heap(Heap *heap) {
  free(heap->values);
  free(heap);
}

void heap_insert(Heap *heap, struct ListNode *node) {
  if (!node) {
    return;
  }

  int idx = heap->size;
  heap->values[idx] = node;
  heap->size++;

  while (idx > 0 && heap->values[(idx - 1) / 2]->val > heap->values[idx]->val) {
    struct ListNode *temp = heap->values[idx];
    heap->values[idx] = heap->values[(idx - 1) / 2];
    heap->values[(idx - 1) / 2] = temp;
    idx = (idx - 1) / 2;
  }
}

struct ListNode *heap_pop(Heap *heap) {
  int idx = 0;
  struct ListNode *root = heap->values[idx];

  heap->size--;
  int max = heap->size;
  heap->values[idx] = heap->values[max];

  while (1) {
    int l = 2 * idx + 1;
    int r = 2 * idx + 2;
    int smallest = idx;
    if (l < max && heap->values[l]->val < heap->values[smallest]->val) {
      smallest = l;
    }
    if (r < max && heap->values[r]->val < heap->values[smallest]->val) {
      smallest = r;
    }
    if (smallest != idx) {
      struct ListNode *temp = heap->values[smallest];
      heap->values[smallest] = heap->values[idx];
      heap->values[idx] = temp;
      idx = smallest;
    } else {
      break;
    }
  }

  if (root->next) {
    heap_insert(heap, root->next);
  }
  return root;
}

// Min-heap approach, O(k * log(n))
struct ListNode *mergeKLists(struct ListNode **lists, int listsSize) {
  Heap *heap = new_heap(listsSize);

  for (int i = 0; i < listsSize; i++) {
    heap_insert(heap, lists[i]);
  }

  if (heap->size == 0) {
    free_heap(heap);
    return NULL;
  }

  struct ListNode *head = heap_pop(heap);
  struct ListNode *current_node = head;

  while (heap->size > 0) {
    current_node->next = heap_pop(heap);
    current_node = current_node->next;
  }

  free_heap(heap);

  return head;
}


// Easy but slow approach, O(k * n), where k = listsSize and n = sum(len(list)
// for list in lists).
int ListNodeValMAX = 10000;
struct ListNode *_mergeKLists(struct ListNode **lists, int listsSize) {
  struct ListNode *node = NULL;
  int min = ListNodeValMAX;
  int idx = -1;

  for (int i = 0; i < listsSize; i++) {
    if (lists[i] && lists[i]->val <= min) {
      idx = i;
      min = lists[i]->val;
    }
  }

  if (idx != -1) {
    printf("%d\n", idx);
    node = lists[idx];
    lists[idx] = lists[idx]->next;

    node->next = _mergeKLists(lists, listsSize);
  }
  return node;
}

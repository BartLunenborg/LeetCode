#include <stdlib.h>

int hIndex(int *citations, int citationsSize) {
  int *buckets = calloc(citationsSize + 1, sizeof(int));
  for (int i = 0; i < citationsSize; i++) {
    buckets[citations[i] > citationsSize ? citationsSize : citations[i]]++;
  }

  int cumSum = 0;
  for (int i = citationsSize; i > 0; i--) {
    cumSum += buckets[i];
    if (cumSum >= i) {
      cumSum = i;
      break;
    }
  }

  free(buckets);
  return cumSum;
}

#include <stdio.h>
#include <stdlib.h>

int calculateMinimumHP(int **dungeon, int dungeonSize, int *dungeonColSize) {
  int max_y = dungeonSize - 1;
  int max_x = dungeonColSize[0] - 1;

  dungeon[max_y][max_x] =
      dungeon[max_y][max_x] < 1 ? 1 - dungeon[max_y][max_x] : 1;

  // Do the bottom row
  int c, r, d;
  for (int x = max_x - 1; x >= 0; x--) {
    r = dungeon[max_y][x + 1];
    c = dungeon[max_y][x];
    dungeon[max_y][x] = r - c < 1 ? 1 : r - c;
  }

  // Do the right-most column
  for (int y = max_y - 1; y >= 0; y--) {
    d = dungeon[y + 1][max_x];
    c = dungeon[y][max_x];
    dungeon[y][max_x] = d - c < 1 ? 1 : d - c;
  }

  // Do the remaining columns right to left
  int r_used;
  int d_used;
  for (int x = max_x - 1; x >= 0; x--) {
    for (int y = max_y - 1; y >= 0; y--) {
      r = dungeon[y][x + 1];
      d = dungeon[y + 1][x];
      c = dungeon[y][x];

      r_used = r - c < 1 ? 1 : r - c;
      d_used = d - c < 1 ? 1 : d - c;
      dungeon[y][x] = r_used < d_used ? r_used : d_used;
    }
  }

  return dungeon[0][0];
}

int main(int argc, char *argv[]) {
  int size = 3;
  int **matrix = malloc(size * sizeof(int));
  for (int i = 0; i < size; i++) {
    matrix[i] = malloc(size * sizeof(int));
  }

  // Example with expected result = 7
  matrix[0][0] = -2;
  matrix[0][1] = -3;
  matrix[0][2] = 3;
  matrix[1][0] = -5;
  matrix[1][1] = -10;
  matrix[1][2] = 1;
  matrix[2][0] = 10;
  matrix[2][1] = 30;
  matrix[2][2] = -5;

  printf("%d\n", calculateMinimumHP(matrix, size, &size));

  // Top left will now contain the result.
  for (int y = 0; y < size; y++) {
    for (int x = 0; x < size; x++) {
      printf("%d ", matrix[y][x]);
    }
    printf("\n");
  }
  return 0;
}

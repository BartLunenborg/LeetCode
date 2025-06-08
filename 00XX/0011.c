int maxArea(int *height, int heightSize) {
  int l = 0;
  int r = heightSize - 1;

  int best = 0;
  int water = 0;
  while (l != r) {
    if (height[l] < height[r]) {
      water = height[l] * (r - l);
      l++;
    } else {
      water = height[r] * (r - l);
      r--;
    }
    best = water > best ? water : best;
  }
  return best;
}

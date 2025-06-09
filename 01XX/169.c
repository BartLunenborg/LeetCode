int majorityElement(int *nums, int n) {
  int val, votes = 0;
  for (int i = 0; i < n; i++) {
    if (votes == 0) {
      val = nums[i];
      votes = 1;
    } else {
      votes += nums[i] == val ? 1 : -1;
    }
    // Early stoppage.
    if (votes > n / 2) {
      return val;
    }
  }
  return val;
}

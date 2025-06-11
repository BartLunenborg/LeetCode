// Definition for a binary tree node.
struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

int helper(struct TreeNode *root, int sum) {
  if (!root) {
    return 0;
  }

  sum = 10 * sum + root->val;

  if (!root->left && !root->right) {
    return sum;
  }

  return helper(root->left, sum) + helper(root->right, sum);
}

int sumNumbers(struct TreeNode *root) { return helper(root, 0); }

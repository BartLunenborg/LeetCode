// Struct as provided
struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

int isSameTree(struct TreeNode *p, struct TreeNode *q) {
  // Base cases
  if (!p && !q) {
    return 1;
  } else if (!p || !q || (p->val != q->val)) {
    return 0;
  }

  // Recursive case
  return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

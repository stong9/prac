int maxHeight(BinaryTree *p) {
  if (!p) return 0;
  int left_height = maxHeight(p->left);
  int right_height = maxHeight(p->right);
  return (left_height > right_height) ? left_height + 1 : right_height + 1;
}
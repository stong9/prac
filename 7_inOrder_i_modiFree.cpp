
void in_order_traversal_iterative(BinaryTree *root) {
  stack<BinaryTree*> s;
  BinaryTree *current = root;
  bool done = false;
  while (!done) {
    if (current) {
      s.push(current);
      current = current->left;
    } else {
      if (s.empty()) {
        done = true;
      } else {
        current = s.top();
        s.pop();
        cout << current->data << " ";
        current = current->right;
      }
    }
  }
}
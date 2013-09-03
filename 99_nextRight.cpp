class Solution {
public:

void connect(TreeLinkNode* p) {
  if (!p) return;
  if (p->left)
  p->left->next = p->right;
  if (p->right)
    p->right->next = (p->next) ?
                               p->next->left :
                               NULL;
  connect(p->left);
  connect(p->right);
}
};
class Solution {

public:

  bool checkSub(TreeNode *p, TreeNode *q) {
      if(p == NULL && q == NULL) return true;
      if(p == NULL || q == NULL) return false;
      if(p->val == q->val && checkSub(p->left, q->left) && checkSub(p->right, q->right))
          return true;
      return false;
  }
  bool isSameTree(TreeNode *p, TreeNode *q) {
      return checkSub(p, q);
  }
};
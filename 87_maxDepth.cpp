/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
         if (!root) return 0;
  stack<TreeNode*> s;
  s.push(root);
  int maxDepth = 0;
  TreeNode *prev = NULL;
  while (!s.empty()) {
    TreeNode *curr = s.top();
    if (!prev || prev->left == curr || prev->right == curr) {
      if (curr->left)
        s.push(curr->left);
      else if (curr->right)
        s.push(curr->right);
    } else if (curr->left == prev) {
      if (curr->right)
        s.push(curr->right);
    } else {
         if (s.size() > maxDepth)
      maxDepth = s.size();
      s.pop();
    }
    prev = curr;
   
  }
  return maxDepth;
        
    }
};
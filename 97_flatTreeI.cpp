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
	TreeNode *flat(TreeNode *node) {
		if (!node) return NULL;
		TreeNode *leftail = flat(node -> left);
		TreeNode *rightail = flat(node -> right);
		if (leftail) leftail -> right = node -> right;
		if (node -> left) {
			node -> right = node -> left;
			node -> left = NULL;
		}
		if (rightail) return rightail;
		if (leftail) return leftail;
		return node;
	}
	void flatten(TreeNode *root) {
		flat(root);
		
	}
};
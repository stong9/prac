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
TreeNode *buildInorderPreorder(vector<int> &in, vector<int> &pre, int start1, int n, int start2, map<int, int>& lookup) {
    assert(n >= 0);
	if (n == 0) return NULL;
	int rootVal = pre[start1];
	int i = lookup[rootVal]-start2;  // the divider's index
	TreeNode *root = new TreeNode(rootVal);
	root->left = buildInorderPreorder(in, pre, start1 + 1, i, start2, lookup);
	root->right = buildInorderPreorder(in, pre, start1+i+1, n-i-1, start2+i+1, lookup);
	return root;
}
TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
    map<int, int> lookup;
	for (int i = 0; i < inorder.size(); i++) {
		
		lookup[inorder[i]] = i;
	}
	return buildInorderPreorder(inorder, preorder, 0, preorder.size(), 0, lookup);
	
	
}
};
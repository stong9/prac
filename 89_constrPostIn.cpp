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
	TreeNode *buildInorderPostorder(vector<int> &in, vector<int> &post, int startPost, int n, int startIn, map<int, int>& lookup) {
		assert(n >= 0);
		if (n == 0) return NULL;
		int rootVal = post[startPost];
		int i = lookup[rootVal]-startIn;  // the divider's index
		TreeNode *root = new TreeNode(rootVal);
		root->left = buildInorderPostorder(in, post, startPost - n + i, i, startIn, lookup);
		root->right = buildInorderPostorder(in, post, startPost-1, n-i-1, startIn+i+1, lookup);
		return root;
	}
	TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		map<int, int> lookup;
		for (int i = 0; i < inorder.size(); i++) {
			
			lookup[inorder[i]] = i;
		}
		return buildInorderPostorder(inorder, postorder, postorder.size()-1, inorder.size(), 0, lookup);
		
		
	}
};
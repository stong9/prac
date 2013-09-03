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

	/*
* preOrder:
* 1) check, if current node is null or leaf, return it.
* 2) init a stack to store the right child tree
* 3) preOrder travel the tree
* 3.1) if current node has left child, store the right child in stack, 
*      change the left child to right.  
* 3.2) else, get the right child from the stack and 
*      set it as the right child as the current node
*
*/
	void flatten(TreeNode *root) {
		

		stack<TreeNode*> stack;
		TreeNode* curr = root;

		while (curr != NULL || !stack.empty()) {

			while (curr->left != NULL) {
				if(curr->right != NULL)  
				stack.push(curr->right);

				curr->right = curr->left;
				curr->left = NULL;
				curr = curr->right;
			}

			if (curr->right == NULL && !stack.empty()){ 
				curr->right = stack.top();
				stack.pop();
			}

			curr = curr->right;
		}
	}
};
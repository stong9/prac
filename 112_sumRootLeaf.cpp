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
	int sumNumbers(TreeNode *root) {
		int num = 0, sum = 0;
		sumNumbersImpl(root, num, sum);
		return sum;
	}

	void sumNumbersImpl(TreeNode *root, int& num, int& sum) {
		if (root == nullptr) return;
		num = num * 10 + root->val;
		if (root->left == nullptr && root->right == nullptr) {
			sum += num;
		} else {
			sumNumbersImpl(root->left, num, sum);
			sumNumbersImpl(root->right, num, sum);
		}
		num /= 10;
	}
};
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
   vector<vector<int> > pathSum(TreeNode *root, int target) {
    // Start typing your C/C++ solution below
	// DO NOT write int main() function
	vector<vector<int> >result;
	vector<int>output;
	int sum = 0;
	solve (root, target, result,output, sum);
	return result;
}
void solve (TreeNode* root, int target, vector<vector<int> >& result, vector<int>& output, int& sum){
	if (root == NULL){
		return;
	}
	sum += root->val;
	output.push_back(root->val);
	if (root->left == NULL && root->right == NULL){
		if (sum == target){
			result.push_back(output);
		}
		output.pop_back();
		sum -= root->val;
		return;
	}
	solve (root->left, target, result, output, sum);
	solve (root->right, target, result, output, sum);
	sum -= root->val;
	output.pop_back();
	return;
}
};
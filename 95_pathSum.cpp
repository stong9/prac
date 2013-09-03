bool hasPathSum(TreeNode *root, int target) {  
	return hasPathSum(root, 0, target);      
}  
bool hasPathSum(TreeNode *root, int sum, int target) {  
	if(root == NULL) return false;  
	sum += root->val;  
	if(root->left == NULL && root->right == NULL) //leaf  
	{  
		 if(sum == target)  
			  return true;  
		 else  
			  return false;  
	}  
	return hasPathSum(root->left, sum, target)   
		   || hasPathSum(root->right, sum, target);      
}  
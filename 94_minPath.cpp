int minDepth(TreeNode *root) {  
  // Start typing your C/C++ solution below  
  // DO NOT write int main() function  
  if(root == NULL)  
	return 0;  
  int lmin = minDepth(root->left);  
  int rmin = minDepth(root->right);  
  if(lmin ==0 && rmin ==0)  
	return 1;  
  if(lmin ==0)  
  {  
	lmin = INT_MAX;  
  }  
  if(rmin ==0)  
  {  
	rmin = INT_MAX;  
  }  
  return min(lmin, rmin) +1;  
}  
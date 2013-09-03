void recoverTree(TreeNode *root)
{     
	TreeNode *f1=NULL, *f2=NULL;
	TreeNode  *current,*pre, *parent=NULL;

	if(root == NULL)
	return;
	bool found = false;
	current = root;
	while(current != NULL)
	{                
		if(current->left == NULL)
		{
			if(parent && parent->val > current->val)
			{
				if(!found)
				{
					f1 = parent;
					found = true;
				}
				f2 = current;
			}
			parent = current;
			current = current->right;     
		}   
		else
		{
			/* Find the inorder predecessor of current */
			pre = current->left;
			while(pre->right != NULL && pre->right != current)
			pre = pre->right;

			/* Make current as right child of its inorder predecessor */
			if(pre->right == NULL)
			{
				pre->right = current;
				current = current->left;
			}

			/* Revert the changes made in if part to restore the original
					tree i.e., fix the right child of predecssor */  
			else
			{
				pre->right = NULL;
				if(parent->val > current->val)
				{
					if(!found)
					{
						f1 = parent;       
						found = true;
					}
					f2 = current;
				}
				parent = current;
				current = current->right;     
			} /* End of if condition pre->right == NULL */
		} /* End of if condition current->left == NULL*/
	} /* End of while */

	if(f1 && f2)
	swap(f1->val, f2->val);
}
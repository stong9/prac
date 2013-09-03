vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
    vector<vector<int> >result;
	vector<int> output;
	stack<TreeNode*> currentLevel, nextLevel;
    bool leftToRight = true;
    currentLevel.push(root);
    while (!currentLevel.empty()) {
        TreeNode *currNode = currentLevel.top();
        currentLevel.pop();
        if (currNode) {
            output.push_back(currNode->val);
            if (leftToRight) {
                nextLevel.push(currNode->left);
                nextLevel.push(currNode->right);
            } else {
                nextLevel.push(currNode->right);
                nextLevel.push(currNode->left);
            }
        }
        if (currentLevel.empty()) {
            if (output.begin() != output.end())
				result.push_back(output);
			output.clear();
            leftToRight = !leftToRight;
            swap(currentLevel, nextLevel);
        }
    }
	return result;
}
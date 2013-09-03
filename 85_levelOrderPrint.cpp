vector<vector<int> > levelOrder(TreeNode *root) {	// Start typing your C/C++ solution below	// DO NOT write int main() function	vector<vector<int> > result;	if (!root) return result;	queue<TreeNode*> currentLevel, nextLevel;	currentLevel.push(root);	vector<int> output;	while (!currentLevel.empty()) {				TreeNode *currNode = currentLevel.front();		currentLevel.pop();		if (currNode) {			output.push_back (currNode->val);			nextLevel.push(currNode->left);			nextLevel.push(currNode->right);		}		if (currentLevel.empty()) {			if (output.begin() != output.end())				result.push_back(output);			swap(currentLevel, nextLevel);			output.clear();		}	}	return result;	}
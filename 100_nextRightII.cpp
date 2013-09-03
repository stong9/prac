class Solution {
public:

	void connect(TreeLinkNode* p) {
		if (p == NULL)
		return;
		while (p&&p->left == NULL && p->right == NULL){
			p = p->next;
		}
		if (p == NULL)
		return;
		TreeLinkNode* rightSibling;
		TreeLinkNode* p1 = p;
		while (p1) {
			TreeLinkNode* p2;
			p2 = p1->next;
			while (p2 && p2->left == NULL && p2->right == NULL){
				p2 = p2->next;
			}
			if (p2){
				if (p2->left){
					rightSibling = p2->left;
				}else{
					rightSibling = p2->right;
				}
			}else{
				rightSibling = NULL;
			}
			if (p1->left && p1->right){
				p1->left->next = p1->right;
				p1->right->next = rightSibling;
			}
			else if (p1->right){
				p1->right->next = rightSibling;
			}
			else {
				p1->left->next = rightSibling;
			}

			p1 = p2;
		}
		if (p->left)
		connect(p->left);
		else
		connect(p->right);
	}
};
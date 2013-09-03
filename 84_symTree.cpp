bool isSymmetric(TreeNode *root) {
    if(root == NULL) return true;

    queue<TreeNode *> lf, rt;
    lf.push(root->left);
    rt.push(root->right);
    TreeNode *l, *r;
    while(!lf.empty() && !rt.empty()) {
        l = lf.front(); r = rt.front();
        lf.pop(); rt.pop();
        if(l == NULL && r == NULL) continue;
        if(l == NULL || r == NULL) return false;
        if(l->val != r->val) return false;
        lf.push(l->left); lf.push(l->right);
        rt.push(r->right); rt.push(r->left);
    }
    if(lf.empty() && rt.empty()) return true;
    else return false;
}
int Solution::minDepth(TreeNode* A) {
    if(!A)
        return 0;
    
    if(!(A->left) and !(A->right))
        return 1;
    int l = INT_MAX , r = INT_MAX;

    if(A->left)
        l = 1 + minDepth(A->left);
    
    if(A->right)
        r = 1 + minDepth(A->right);
    
    return min(l , r);
}

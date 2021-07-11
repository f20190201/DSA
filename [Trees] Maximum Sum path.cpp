// There can be 2 possibilities for a node.
// It can be the LCA of the path.
// It can be just another node in the path - maybe the start node or not the start node.

int res;

int solve(TreeNode* A){
    
    if(!A)
        return 0;

    int leftSum = solve(A->left);
    int rightSum = solve(A->right);
  
// Calculation for just another node of the path 

    int curr = max(A->val , A->val + max(leftSum , rightSum));
 
// Calculation for LCA of the path
 
    int temp = max(curr , leftSum + rightSum + A->val);
    res = max(res , temp);

    return curr;
}

int Solution::maxPathSum(TreeNode* A) {
    res = INT_MIN;

    solve(A);

    return res;
}

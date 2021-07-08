// If NULL, then return NULL else if it is a leaf node, return as it is.
// Recur for left and right subtrees and append it to root
// If right child is null return leftchild and vice versa
// If both exist, return the root itself

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* Solution::solve(TreeNode* A) {
    if(!A)
        return NULL;
    
    if(A->left == NULL and A->right == NULL)
        return A;
    
    A->left = solve(A->left);
    A->right = solve(A->right);
    
    if(A->left == NULL)
        return A->right;
    if(A->right == NULL)
        return A->left;
    
    return A;


}

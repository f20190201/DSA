// A tree is balanced only if abs(left subtree height - right subtree height) <= 1 and all its subtrees are balanaced

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int height(TreeNode* A){
    if(!A)
        return 0;
    
    return 1 + max(height(A->left) , height(A->right));

}

bool isbalanced(TreeNode* A){
    
    if(!A)
        return 1;
    
    int leftHeight = height(A->left);
    int rightHeight = height(A->right);

    if(abs(leftHeight - rightHeight) > 1)
        return 0;
    
    if(isbalanced(A->left) and isbalanced(A->right))
        return 1;
    
    return 0;

}



int Solution::isBalanced(TreeNode* A) {

    return isbalanced(A);
}

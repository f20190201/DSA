// Make a helper function that checks if 2 BTs are symmetric
// Pass A->left and A->right as the roots of two trees

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int helper(TreeNode* n1 , TreeNode* n2){
    
    if(!n2 and !n1)
        return 1;

    if(!n1 or !n2)
        return 0;
    
    if(n1->val != n2->val)
        return 0;
    
    return (helper(n1->left , n2->right) and helper(n1->right , n2->left));

}


int Solution::isSymmetric(TreeNode* A) {


    return helper(A->left , A->right);
}

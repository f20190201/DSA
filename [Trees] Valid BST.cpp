/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

bool check(TreeNode* A , int min , int max){
    if(!A)
        return 1;
    
    if(A->val < min or A->val > max)
        return 0;
    
    return (check(A->left , min , A->val - 1) and check(A->right , A->val + 1 , max));
}

int Solution::isValidBST(TreeNode* A) {
    
    return check(A , INT_MIN , INT_MAX);
}

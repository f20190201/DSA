/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void f(TreeNode* A){
        
        if(A == NULL || (A->left == NULL && A->right == NULL))
            return;
        
        f(A->left);
        
        TreeNode* temp = A->right;
        
        A->right = A->left;
        
        A->left = NULL;
        
        TreeNode* tail = A;
        
        while(tail->right)
            tail = tail->right;
        
        tail->right = temp;
        
        f(temp);
        
        return;
    }
    
    void flatten(TreeNode* root) {
        f(root);
        
        return;
    }
};
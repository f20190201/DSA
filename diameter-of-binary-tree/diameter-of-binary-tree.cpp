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
    int ans;
    
    int solve(TreeNode* A){
        if(A == NULL)
            return 0;
        
        int ld = solve(A->left) , rd = solve(A->right);
        
        ans = max(ans , 1 + ld + rd);
        
        return 1 + max(ld , rd);
        
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        ans = 0; 
        
        solve(root);
        
        return ans - 1;
    }
};
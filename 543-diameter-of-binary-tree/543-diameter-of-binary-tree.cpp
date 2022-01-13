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
    int globalMax;
    
    int f(TreeNode* root){
        
        if(root == NULL)
            return 0;
        
        int l = f(root->left) , r = f(root->right);
        
        globalMax = max(globalMax , 1 + l + r);
        
        return 1 + max(l , r);
        
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        globalMax = 0;
        
        f(root);
        
        return globalMax - 1;
    }
};
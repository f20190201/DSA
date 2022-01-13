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
    
    int sumPath(TreeNode* root){
        if(root == NULL)
            return 0;
        
        int l = max(sumPath(root->left) , 0) , r = max(sumPath(root->right) , 0);
        
        globalMax = max(globalMax , root->val + l + r);
        
        return (root->val + max(l , r));
    }
    
    int maxPathSum(TreeNode* root) {
        
        globalMax = INT_MIN;
        
        sumPath(root);
        
        return globalMax;
    }
};
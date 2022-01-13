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
    
    int pathSum(TreeNode* root){
        
        if(root == NULL)
            return 0;
        
        int l = pathSum(root->left) , r = pathSum(root->right);
        
        l = max(l , 0);
        r = max(r , 0);
        
        globalMax = max(globalMax , root->val + l + r);
        
        return (root->val + max(l , r));
    }
    
    int maxPathSum(TreeNode* root) {
        
        globalMax = INT_MIN;
        
        pathSum(root);
        
        return globalMax;
    }
};
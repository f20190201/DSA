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
    bool flag;
    
    vector<long long int> validateBST(TreeNode* node){
        
        if(node == NULL)
            return {LLONG_MAX , LLONG_MIN};
        
        if(node->left == NULL && node->right == NULL)
            return {node->val , node->val};
        
        vector<long long int>leftSubtree = validateBST(node->left) , rightSubtree = validateBST(node->right);
        
        
        if(node->val > leftSubtree[1] && node->val < rightSubtree[0]){
            flag = flag && 1;
        }
        
        else
            flag = flag && 0;
              
        
        
        return {min({leftSubtree[0] , rightSubtree[0] , (long long int)node->val}) , max({leftSubtree[1] , rightSubtree[1] , (long long int)node->val})};
    }
    
    bool isValidBST(TreeNode* root) {
        
        if(!root || (!root->left && !root->right))
            return 1;
        
        flag = 1;
        
        validateBST(root);    
        
        return flag;
    }
};
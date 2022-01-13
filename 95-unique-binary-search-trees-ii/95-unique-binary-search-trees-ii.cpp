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
    
    vector<TreeNode*> solve(int start , int end){
        
        vector<TreeNode*> result;
        
        if(start > end){
            result.push_back(NULL);
            return result;
        }
        
        if(start == end){
            result.push_back(new TreeNode(start));
            return result;
        }
        
        for(int i = start ; i <= end ; i++){
            
            vector<TreeNode*> left = solve(start , i - 1) , right = solve(i + 1 , end);
            
            for(auto x : left){
                for(auto y : right){
                    
                    TreeNode* root = new TreeNode(i);
                    root->left = x;
                    root->right = y;
                    
                    result.push_back(root);
                    
                }
            }
        }
        
        return result;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        
        return solve(1 , n);
    }
};
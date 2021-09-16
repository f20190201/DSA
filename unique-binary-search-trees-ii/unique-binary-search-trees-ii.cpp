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
        
        vector<TreeNode*> res;
        
        if(start > end){
            res.push_back(NULL);
            return res;
        }
        
        if(start == end){
            res.push_back(new TreeNode(start));
            return res;
        }
        
        for(int i = start ; i <= end ; i++){
            vector<TreeNode*> left = solve(start , i - 1) , right = solve(i + 1 , end);
            
            for(auto x : left){
                for(auto y : right){
                    
                    TreeNode* root = new TreeNode(i);
                    root->left = x;
                    root->right = y;
                    res.push_back(root);
                }
            }
        }
        
        return res;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*>v;
        
        if(n == 0)
            return v;
        
        return solve(1 , n);
    }
};
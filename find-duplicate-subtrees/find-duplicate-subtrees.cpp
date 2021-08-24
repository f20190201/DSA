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
    map<string , pair<TreeNode* , int>> mp;
    
    string solve(TreeNode* root){
        if(root == NULL)
            return "@";
        
        string s = "";
        bool isLeaf = 0;
        
        if(root->left == NULL && root->right == NULL){
            
            s = to_string(root->val);
            
            isLeaf = 1;
        }
        
        if(!isLeaf){
            
            s += to_string(root->val);
            s += " ";
            s += solve(root->left);
            s += " ";
            s += solve(root->right);
        }
        
        if(mp.count(s)){
            mp[s].second++;
        }
        else{
            mp[s].first = root;
            mp[s].second = 1;
        }
        
        return s;
            
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        mp.clear();
        
        solve(root);
        
        vector<TreeNode*> res;
        
        for(auto it = mp.begin() ; it != mp.end() ; ++it){
            if(it->second.second >= 2)
                res.push_back(it->second.first);
        }
        
        return res;
    }
};

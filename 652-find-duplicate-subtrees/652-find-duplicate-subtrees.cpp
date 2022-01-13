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
    
    string solve(TreeNode* root , string s){
        
        if(root == NULL){
            s += "*";
            return s;
        }
        
        bool isLeaf = 0;
        
        if(root->left == NULL && root->right == NULL){
            s += " ";
            s += to_string(root->val);
            
            isLeaf = 1;
        }
        
        string left = solve(root->left , s) , right = solve(root->right , s);
        
        if(!isLeaf){
            
            s += left;
            s += " ";
            s += to_string(root->val);
            s += right;
            s += " ";
        }
        
        if(mp.count(s) == 0){
            mp[s].first = root;
            mp[s].second = 1;
        }
        
        else
            mp[s].second++;
        
        return s;
        
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        
        mp.clear();
        
        vector<TreeNode*> v;
        
        string s = "";
        
        solve(root , s);
        
        for(auto it : mp){
            if(it.second.second >= 2)
                v.push_back(it.second.first);
        }
        
        return v;
    }
};
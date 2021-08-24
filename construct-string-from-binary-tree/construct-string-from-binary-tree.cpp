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
    string s;
    
    void solve(TreeNode* A){
        if(A == NULL){
            return;
        }
        
        if(A->left == NULL && A->right == NULL){
            s += to_string(A->val);
            return;
        }
        
        s += to_string(A->val);
        
        if(A->left){
            s += "(";
            solve(A->left);
            s += ")";    
        }
        
        else
            s += "()";
        
        if(A->right){
            s += "(";
            solve(A->right);
            s += ")";
        }
        
        // else
        //     s += "()";
        
        return;
    }
    
    string tree2str(TreeNode* root) {
        s = "";
        
        solve(root);
        
        return s;
    }
};
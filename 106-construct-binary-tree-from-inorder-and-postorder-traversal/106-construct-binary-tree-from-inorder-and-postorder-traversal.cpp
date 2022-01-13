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
    int index;
    
    TreeNode* fun(vector<int>& inorder, vector<int>& postorder , int start , int end){
        
        if(start > end){
            return NULL;
        }
        
        int pos , val = postorder[index];
        index--;
        
        for(int i = start ; i <= end ; i++){
            
            if(inorder[i] == val){
                pos = i;
                break;
            }
        }
        
        TreeNode* root = new TreeNode(val);
        
        root->right = fun(inorder , postorder , pos + 1 , end);
        root->left = fun(inorder , postorder , start , pos - 1);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        index = postorder.size() - 1;
        
        return fun(inorder , postorder , 0 , inorder.size() - 1);
    }
};
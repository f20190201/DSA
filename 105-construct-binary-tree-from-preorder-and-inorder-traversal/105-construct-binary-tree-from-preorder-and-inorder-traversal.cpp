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
    
    TreeNode* fun(vector<int>& preorder, vector<int>& inorder , int start , int end){
        
        if(start > end){
            return NULL;
        }
        
        int pos , val = preorder[index];
        index++;
        
        for(int i = start ; i <= end ; i++){
            
            if(inorder[i] == val){
                pos = i;
                break;
            }
        }
        
        TreeNode* root = new TreeNode(val);
        
        root->left = fun(preorder , inorder , start , pos - 1);
        root->right = fun(preorder , inorder , pos + 1 , end);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        index = 0;
        
        return fun(preorder , inorder , 0 , preorder.size() - 1);
    }
};
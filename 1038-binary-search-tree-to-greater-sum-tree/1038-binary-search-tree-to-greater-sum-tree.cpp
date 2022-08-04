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
    vector<TreeNode*> A;
    void inOrder(TreeNode* root){
        if(root == NULL)
            return;
        
        inOrder(root->left);
        A.push_back(root);
        inOrder(root->right);
        
        return;
    }
    TreeNode* bstToGst(TreeNode* root) {
        A.clear();
        inOrder(root);
        vector<int> suffixSum(A.size() , 0);
        
        suffixSum[A.size() - 1] = A.back()->val;
        
        for(int i = A.size() - 2 ; i >= 0 ; i--){
            suffixSum[i] = suffixSum[i + 1] + A[i]->val;    
        }
        
        for(int i = 0 ; i < A.size() ; i++){
            A[i]->val = suffixSum[i];
        }
        
        return root;
    }
};
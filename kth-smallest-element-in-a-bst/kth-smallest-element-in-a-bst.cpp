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
    priority_queue<int> maxHeap;
    
    void traverse(TreeNode* root , int k){
        if(!root)
            return;
        maxHeap.push(root->val);
        
        if(maxHeap.size() > k)
            maxHeap.pop();
        
        traverse(root->left , k);
        traverse(root->right , k);
        return;
        
    }
    
    int kthSmallest(TreeNode* root, int k) {
        while(maxHeap.size() != 0)
            maxHeap.pop();
        
        traverse(root , k);
        return maxHeap.top();
        
    }
};
// In order traversal of BST is a sorted array

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int>inOrderSequence;

void inOrderTraverse(TreeNode* A , int B){
    
    if(!A)
        return;

    inOrderTraverse(A->left , B);
    inOrderSequence.push_back(A->val);
    inOrderTraverse(A->right , B);    
    return;

}

int Solution::kthsmallest(TreeNode* A, int B) {
    inOrderSequence.clear();

    inOrderTraverse(A , B);
  
    return inOrderSequence[B - 1];


}

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* Solution::solve(TreeNode* A, TreeNode* B) {
    if(!A and !B)
        return NULL;
    
    int curr = 0;
    TreeNode* head;

    if(!A){
        curr += B->val;
        head = new TreeNode(curr);
        head->left = solve(NULL , B->left);
        head->right = solve(NULL , B->right);
    }

    else if(!B){
        curr += A->val;
        head = new TreeNode(curr);
        head->left = solve(A->left ,NULL);
        head->right = solve(A->right ,NULL);
    }

    else{
        curr += (A->val + B->val);
        head = new TreeNode(curr);
        head->left = solve(A->left , B->left);
        head->right = solve(A->right , B->right);
    }

    return head;
}

----------------------------------------------------------------------------------------
  
  
  TreeNode* Solution::solve(TreeNode* A, TreeNode* B) {
    if(A==NULL)
        {
            return B;
        }
    if(B==NULL)
        {
            return A;
        }
    A->val+=B->val;
    A->left=solve(A->left,B->left);
    A->right=solve(A->right,B->right);
    return A;
}

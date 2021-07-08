// Middle element is always the root. Recur the same for left and right subarrays

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode* toBST(const vector<int> &A , int start , int end){
    if(start > end)
        return NULL;
    
    int middle = start + (end - start) / 2;

    TreeNode* head = new TreeNode(A[middle]);

    head->left = toBST(A , start , middle - 1);
    head->right = toBST(A , middle + 1 , end);

    return head;

}

TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {


    return toBST(A , 0 , A.size() - 1);

}

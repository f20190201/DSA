// Cartesian tree :  is a heap ordered binary tree, where the root is greater than all the elements in the subtree.
// Idea is to find the max_element in the array, that would be the root.
// Recur the same for left and right sub arrays

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int find_max(vector<int> &A , int start , int end){
    int res = INT_MIN , ans = -1;
    int i;
    for(i = start ; i <= end ; i++){
        if(A[i] > res){
            ans = i;
            res = A[i];
        }
    }    
    return ans;
}


TreeNode* solve(vector<int> &A , int start , int end){
    
    if(start > end)
        return NULL;

    int index = find_max(A , start , end);

    TreeNode* root = new TreeNode(A[index]);

    if(start == end)
        return root;

    root->left = solve(A , start , index - 1);
    root->right = solve(A , index + 1 , end);

    return root;

}

TreeNode* Solution::buildTree(vector<int> &A) {

    return solve(A , 0 , A.size() - 1);

}

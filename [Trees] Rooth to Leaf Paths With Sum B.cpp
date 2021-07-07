/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

vector<vector<int>> result;

void pathToLeaf(TreeNode* A , int sum , vector<int>v , int B){
    if(!A)
        return;
    
    v.push_back(A->val);
    sum = sum + A->val;
    
    if(A->left == NULL and A->right == NULL and sum == B){
        result.push_back(v);
        v.clear();
        return;
    }

    pathToLeaf(A->left , sum , v , B);
    pathToLeaf(A->right , sum , v , B);

    return;

}


vector<vector<int> > Solution::pathSum(TreeNode* A, int B) {
    result.clear();

    vector<int>v;

    pathToLeaf(A , 0 , v , B);

    return result;
}


--------------------------------------------------------------------------------------------
  
  
  void pathSumHelper(TreeNode *root, int remainingSum, vector<int> &current, vector<vector<int> > &ret) {
    if (root == NULL) return;

    remainingSum -= root->val;
    current.push_back(root->val);

    // If we have reached a leaf, time to check the sum. 
    if (root->left == NULL && root->right == NULL) {
        if (remainingSum == 0) {
            ret.push_back(current);
        }
        current.pop_back();
        return;
    }

    // check the left and the right subtree.
    pathSumHelper(root->left, remainingSum, current, ret);
    pathSumHelper(root->right, remainingSum, current, ret);
    current.pop_back();
    return;
}

vector<vector<int> > Solution::pathSum(TreeNode *root, int sum) {
    vector<vector<int> > ans;
    vector<int> current;
    pathSumHelper(root, sum, current, ans);
    return ans;
}

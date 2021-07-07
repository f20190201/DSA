/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> v;

void inOrder(TreeNode* A){
    if(!A)
        return;
    
    inOrder(A->left);
    v.push_back(A->val);
    inOrder(A->right);

    return;
}

vector<int> Solution::recoverTree(TreeNode* A) {
    v.clear();

    inOrder(A);

    vector<int> duplicate = v;

    sort(duplicate.begin() , duplicate.end());

    vector<int> result;

    for(int i = 0 ; i < duplicate.size() ; i++){
        if(v[i] != duplicate[i])
            result.push_back(duplicate[i]);
    }

    return result;


}


----------------------------------------------------------------------------------------------------
  
  
  

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int>result;

int pathSum(TreeNode* A , long long int sum){
    
    if(!A)
        return 0;
    
    sum = (((sum)*10) % 1003 + (A->val) % 1003) % 1003;

    if(A->left == NULL and A->right == NULL){
        return sum;
    }

    return pathSum(A->left , sum % 1003) + pathSum(A->right , sum % 1003);
}

int Solution::sumNumbers(TreeNode* A) {

    return pathSum(A , 0) % 1003;
}

------------------------------------------------------------------------------------
  
  
  vector<int>result;

void pathSum(TreeNode* A , int sum){
    
    sum = (sum*10 + A->val) % 1003;
    
    if(A->left == NULL and A->right == NULL){
        result.push_back(sum);
        return;
    }

    if(A->left)
        pathSum(A->left , (sum) % 1003);
    
    if(A->right)
        pathSum(A->right , (sum) % 1003);

    return;
}

int Solution::sumNumbers(TreeNode* A) {
    result.clear();

    long long int ans = 0;
    long long int sum = 0;
    pathSum(A , sum);

    for(int i = 0 ; i < result.size() ; i++){
        ans += ((result[i]) % 1003);
    }

    return ans % 1003;
}

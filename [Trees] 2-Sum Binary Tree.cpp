// Traverse tree level order and make a map that conatains all the values encountered till now

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */



int Solution::t2Sum(TreeNode* A, int B) {
    map<int , int>mp;
    queue<TreeNode*>q;

    q.push(A);

    while(!q.empty()){
        TreeNode* curr = q.front();
        q.pop();

        int x = B - curr->val;

        if(x >= 0){
            if(mp.count(x))
                return 1;
        } 

        mp[curr->val]++;
        if(curr->left)
            q.push(curr->left);
        if(curr->right)
            q.push(curr->right);


    }

    return 0;

}


------------------------------------------------------------------------
    
    
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
unordered_map<int , int> mp;

bool solve(TreeNode* A , int B){
    
    if(!A)
        return 0;

    bool left = solve(A->left , B) , right = solve(A->right , B);

    if(left || right)
        return 1;
    
    if(mp.count(B - A->val) == 1)
        return 1;
    
    else
        mp[A->val]++;
    
    return 0;
}

int Solution::t2Sum(TreeNode* A, int B) {
    mp.clear();

    bool ans = solve(A, B);

    return ans;
}


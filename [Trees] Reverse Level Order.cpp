// Reverse the vector obtained by traversing level order from right to left instead of left to right

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


vector<int> Solution::solve(TreeNode* A) {
    vector<int>result;
    queue<TreeNode*>q;

    q.push(A);

    while(!q.empty()){
        auto top = q.front();
        q.pop();

        result.push_back(top->val);

        if(top->right)
            q.push(top->right);
        
        if(top->left)
            q.push(top->left);
        


    }

    reverse(result.begin() , result.end());

    return result;
}

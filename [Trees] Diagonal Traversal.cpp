// Make a queue that stores the left nodes.
// Recur for the right nodes till they become NULL and print

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> result;

void traverse(TreeNode* A){
    if(!A)
        return;
    queue<TreeNode*>q;

    q.push(A);

    while(!q.empty()){

        int n = q.size();

        while(n--){
            auto top = q.front();
            q.pop();

            while(top){
                result.push_back(top->val);

                if(top->left)
                    q.push(top->left);
                
                top = top->right;
            }
        }
    }

    return;
    
}

vector<int> Solution::solve(TreeNode* A) {
    result.clear();

    traverse(A);

    return result;

}

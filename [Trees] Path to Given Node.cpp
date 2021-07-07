bool hasPath(Node *root, vector<int>& arr, int x)
{
    // if root is NULL
    // there is no path
    if (!root)
        return false;
     
    // push the node's value in 'arr'
    arr.push_back(root->data);   
     
    // if it is the required node
    // return true
    if (root->data == x)   
        return true;
     
    // else check whether the required node lies
    // in the left subtree or right subtree of
    // the current node
    if (hasPath(root->left, arr, x) ||
        hasPath(root->right, arr, x))
        return true;
     
    // required node does not lie either in the
    // left or right subtree of the current node
    // Thus, remove current node's value from
    // 'arr'and then return false   
    arr.pop_back();
    return false;           
}

-------------------------------------------------------------------------------------
  
  
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
// vector<int> temp;

void path(TreeNode* A , vector<int>temp , int B){
    if(!A){
        return;
    }
    temp.push_back(A->val);
    
    if(A->val == B){
        result = temp;
        return;
    }

    path(A->left , temp , B);
    path(A->right , temp , B);

    return;
}

vector<int> Solution::solve(TreeNode* A, int B) {
    result.clear();
    vector<int> temp;
    path(A , temp , B);

    return result;
}





bool isIdentical(Node *r1, Node *r2)
    {
   // If both nodes are NULL, return true and continue the search  
        if(r1 == NULL && r2 == NULL)
            return 1;
      
  // If one of them is NULL, return false and end the search
        else if(r1 == NULL || r2 == NULL)
            return 0;
   
  // If both aren't NULL, compare the data and also the fact if the right and left subtrees are identical   
        else{
            bool c1 = (r1->data == r2->data);
            bool c2 = isIdentical(r1->left, r2->left);
            bool c3 = isIdentical(r1->right, r2->right);
            return (c1&&c2&&c3);
        }
        
    }


----------------------------------------------------------------------------------
    
    /**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void traversal(TreeNode* A , string &s){

    if(!A){
        s += '$';
        return;
    }
    
    s += char(A->val);

    if(A->left)
        traversal(A->left , s);
    if(A->right)
        traversal(A->right , s);

    return;

}

int Solution::isSameTree(TreeNode* A, TreeNode* B) {
    string s1 = "" , s2 = "";

    traversal(A , s1);
    traversal(B , s2);

    return (s1 == s2);
}


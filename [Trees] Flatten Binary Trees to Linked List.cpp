void f(TreeNode *A){
    
    if(!A or (!(A->left) and !(A->right)))
        return;
    
    if(A->left){

      // If left node exists, flatten left node recursively
        f(A->left);
      // Replace right node of root with left node of root
        TreeNode* tempRight = A->right;
        A->right = A->left;

        A->left = NULL;

        TreeNode* curr = A->right;
    // Find the last node of old left subtree, so as to find the node to attach old right subtree
        while(curr->right)
            curr = curr->right;
    // Attach old left end to old right start
        curr->right = tempRight;
    }
    // Recursion for right subtree
    f(A->right);

}

TreeNode* Solution::flatten(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    f(A);

    return A;
}

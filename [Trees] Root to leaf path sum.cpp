// We check if the right or left subtree has a sum of (S - curr_node->data), if yes, then return 1
// If we reach the leaf, and S isn't equal to leaf->data, return 0, else return 1

bool hasPathSum(Node *root, int S) {
    
    
    if((root->left == NULL) && (root->right == NULL)){
       return(S == root->data);
    }
       bool left = 0;
       bool right = 0;
        
    if(root->left != NULL)
        left = left || hasPathSum(root->left , S-(root->data));
    
    if(root->right != NULL)
        right = right || hasPathSum(root->right , S-(root->data));
    
        return (right || left);
    
}
// 2nd way of putting it

bool hasPathSum(Node *root, int S) {
 
    if(root == NULL)
        return 0;
    
    else if((root->left == NULL) && (root->right == NULL)){
       return(S == root->data);
    }
       
    else
        return (hasPathSum(root->left, S - root->data) || hasPathSum(root->right, S - root->data));
}

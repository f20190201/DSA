struct Node{
    int data;
    Node *left , *right;
    
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
}

// This function returns NULL if the node itself is NULL or both its children are null(since in this this case, neither of n1 and n2 have been found and we've reached leaf)
// If node->data is either of n1 or n2, then we return that node itself, since that could possibly be an answer
// If the left child is NULL and right isn't, we know for sure that the answer would be found in right subtree, so we recursively call and return right LCA. Same for left subtree


Node* LCA(Node* root , int n1 , int n2){
    if(root == NULL)
        return NULL;
    
    if(root->data == n1 || root->data == n2)
        return root;
    
    Node* left = LCA(root->left , n1 , n2);
    Node* right = LCA(root->right , n1 , n2);
    
    if(left != NULL && right != NULL)
        return root;
        
    if(left == NULL && right == NULL)
        return NULL;
        
    return (left != NULL) ? left : right;
}

struct Node{
    int data;
    Node *left , *right;
    
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
}

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

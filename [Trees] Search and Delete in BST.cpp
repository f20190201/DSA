

Node* InOrderSuccessor(Node* root){
    Node* curr = root;
    while(curr && curr->left != NULL)
        curr = curr->left;
    return curr;
}

Node* DeleteBST(Node* root , int item){  
    
    if(item < root->data)
        root->left = DeleteBST(root->left , item);
    
    else if(item > root->data)
        root->right = DeleteBST(root->right , item);
    
    else{
        
        if(root->left == NULL){
            Node* temp1 = root->right;
            free(root);
            return temp1;
        }
        
        if(root->right == NULL){
            Node* temp2 = root->left;
            free(root);
            return temp2;
        }
        
        Node* temp = InOrderSuccessor(root->right);
        root->data = temp->data;
        root->right = DeleteBST(root->right , temp->data);
    }
    return root;
    
}



Node* Ancestor(Node* root , int &k , int node , int &result){
    if(root == NULL)
        return NULL;
    
    if(root->data == node || 
    (Ancestor(root->left , k , node , result)) || 
    (Ancestor(root->right , k , node , result)))
    
    {
        
        if(k > 0)
            k--;
        
        else if(k == 0){
            result = root->data;
            return NULL;
            
        }
            
        return root;
        
    }
    
}

int kthAncestor(Node *root, int k, int node)
{
    // Code here
    int answer;
    Node* result = Ancestor(root , k , node , answer);
    if (result != NULL) 
        return -1;
    
    return answer;
    
    
}

//Use recursion to convert left subtree first then right
// After converting each, make the successor of left subtree as root and root's predecessor as left last. Same for right

class Solution
{
    public: 
    //Function to convert binary tree to doubly linked list and return it.
    vector<Node*>v;
    
    Node* solve(Node* root){
            
        if(root == NULL)
            return NULL;
        
        if(root->left){
            Node* l = solve(root->left);
            
            while(l->right != NULL)
                l = l->right;
            //Joining left subtree to root
            l->right = root;
            root->left = l;
        }
        
        if(root->right){
            Node* r = solve(root->right);
            
            while(r->left != NULL)
                r = r->left;
            //joining right subtree to root
            r->left = root;
            root->right = r;
        }
        
        return root;
        
    }
    
    Node * bToDLL(Node *root)
    {
        if(root == NULL)
            return NULL;
            
        root = solve(root);
        //finding the start of inorder of BT
        while(root->left)
            root = root->left;
        
        return root;
    }
};

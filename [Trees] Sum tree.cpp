// A leaf node is a sum tree. A null node is a sum tree.
// We make a function which returns if the node is leaf or not. If this function returns true, left_sum = root->left->data (for right_sum respectively)
// At any point if we find the child isn't a sum tree then we return false.
// It is important to note that if a tree is a sum tree then then sum of the node of all its subtrees is 2*(node->data)

bool isleaf(Node* root){
        if(root == NULL)
            return 0;
        if((root->left == NULL) && (root->right == NULL))
            return 1;
        return 0;
    }
   
    bool isSumTree(Node* root)
    {
        
         if((root == NULL) || isleaf(root))
            return 1;
        
        int ls , rs;
        
        if(isSumTree(root->left) && isSumTree(root->right)){
           if(root->left == NULL)
                ls = 0;
            else if(isleaf(root->left))
                ls = root->left->data;
            else
                ls = 2*(root->left->data);
            
            if(root->right == NULL)
                rs = 0;
            else if(isleaf(root->right))
                rs = root->right->data;
            else
                rs = 2*(root->right->data);
                
            return(root->data == (ls + rs));
        }
        return 0;
        
         
         
    }

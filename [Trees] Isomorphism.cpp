bool isIsomorphic(Node *root1,Node *root2)
    {
    //add code here.
    
    if(root1 == NULL && root2 == NULL)
        return 1;
    
    else if(root1 == NULL || root2 == NULL)
        return 0;
    
    else if(root1->data != root2->data)
        return 0;
    
    
    else{
        NotFlippedLeft = isIsomorphic(root1->left,root2->left);
        NotFlippedRight =  isIsomorphic(root1->right,root2->right);
        
        FlippedLeft =  isIsomorphic(root1->left,root2->right);
        FlippedRight =  isIsomorphic(root1->right,root2->left);
        
        return ((NotFlippedLeft && NotFlippedRight) || 
        (FlippedLeft && FlippedRight));
    }
    
    }

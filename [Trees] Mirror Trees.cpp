

bool areMirror(Node* a, Node* b) {
   
  // If both nodes are NULL, the tree is mirror
    if(a == NULL && b == NULL)
        return 1;
  
  // If one of them is NULL and the other isn't, return false
    else if(a == NULL || b == NULL)
        return 0;
  
  // If both are not NULL, check for the data on that particular node and then check if (a->left is same as b->right) and (a->right is same as b->left)
    else{
        bool c1 = (a->data == b->data);
        bool c2 = areMirror(a->left, b->right);
        bool c3 = areMirror(a->right, b->left);
        
        return (c1&&c2&&c3);
    }
    }

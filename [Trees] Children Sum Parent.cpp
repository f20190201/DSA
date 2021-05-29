int isSumProperty(Node *root)
{
 // Add your code here
 bool left = 1;
 bool right = 1;
 
 if(!root)
    return 0;
 
 if(!root->left && !root->right)
    return 1;
 
 int sum = 0;
 
 if(root->left){
    sum+=root->left->data;
    left = left && isSumProperty(root->left);
 }
 if(root->right){
    sum+= root->right->data;
    right = right && isSumProperty(root->right);
 }

 if(sum != root->data)
    return 0;
 
 return (left && right);
 
 
}

----------------------------------
  
 int isSumProperty(struct Node *node) 
{
    int left_data = 0, right_data = 0;

    //if node is null or both child nodes are null, we return true.
    if (node == NULL ||(node->left == NULL && node->right == NULL))
        return 1;
        
    else {

        //if left child is not null then we store its value.
        if (node->left != NULL)
            left_data = node->left->data;

        //if right child is not null then we store its value.
        if (node->right != NULL)
            right_data = node->right->data;

        //if sum of stored data of left and right child is equal to the current
        //node data and recursively for the left and right subtree, parent data 
        //is equal to sum of child data then we return true.
        if ((node->data == left_data + right_data) &&
            isSumProperty(node->left) &&
            isSumProperty(node->right))
            return 1;
            
        //else we return false.
        else
            return 0;
    }
}

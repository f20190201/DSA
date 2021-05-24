// If the current node is a leaf then increase the leaf count by one else recursively call the children, whichever is valid and check if they are leaf or not. 

int countLeaves(Node* root)
{
  
  if((root->left == NULL) && (root->right == NULL)){
      return 1;
  }
  
  else if ((root->left == NULL) && (root->right != NULL))
    return countLeaves(root->right);
    
  else if ((root->left != NULL) && (root->right == NULL))
    return countLeaves(root->left);
    
  return (countLeaves(root->right)+countLeaves(root->left)) ;

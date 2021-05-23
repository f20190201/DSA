// We store the left and right heights of the tree in lh and rh respectively.
// If the current node is included, currDiameter is taken as the value otherwise, max(lDiameter , rDiameter) is taken as the value.
//This solves the problem in O(N)

int CalculateDiameter(Node* root , int* height){
    if(root == NULL){
        *height = 0;
        return 0;
    }
    int lh = 0 , rh = 0;
    
    int lDiameter = CalculateDiameter(root->left , &lh);
    int rDiameter = CalculateDiameter(root->right , &rh);
    
    int currDiameter = lh + rh + 1;
    
    *height = max(lh , rh) + 1;
    
    return max(currDiameter , max(lDiameter , rDiameter));
}

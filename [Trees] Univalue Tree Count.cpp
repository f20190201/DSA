// A node contributes to being univalue iff both(or whichever exists) of its children are univalue and both(or whichever exists) are equal to root

// https://binarysearch.com/problems/Univalue-Tree-Count

bool isUniVal(Tree* root , int &count){
    if(!root)
        return 1;

    if(root->left == NULL && root->right == NULL){
        count++;
        return 1;
    }
    
    bool left = isUniVal(root->left , count);
    bool right = isUniVal(root->right , count);

    int leftVal = (root->left) ? root->left->val : root->val;
    int rightVal = (root->right) ? root->right->val : root->val;

    if(left && right && root->val == leftVal && root->val == rightVal){
        count++;
        return 1;
    }

    
    return 0;
}

int solve(Tree* root) {
    int count = 0;

    isUniVal(root , count);

    return count;
}

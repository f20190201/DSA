// Idea is to traverse only those children which are inside the range and eliminate others
// https://binarysearch.com/problems/Count-BST-Nodes-in-a-Range

int l , h;

int nodeCount(Tree* root){
    int count = 0;
    
    if(root == NULL)
        return count;

    int val = root->val;

    if(val < l)
        count += nodeCount(root->right);
    
    else if(val > h)
        count += nodeCount(root->left);
    
    else if(val >= l && val <= h)
        count += (1 + nodeCount(root->left) + nodeCount(root->right));
    
    return count;
}

int solve(Tree* root, int lo, int hi) {
    l = lo;
    h = hi;

    return nodeCount(root);
}

//https://youtu.be/4fiDs7CCxkc

struct Node{
    int Min = INT_MAX;
    int Max = INT_MIN;
    int size = 0;
    bool isValid = 1;

    // Node(bool x , int a , int b , int c) : isValid(x) , Min(a) , Max(b) , len(c){};

};

Tree* res;
int maxLen;

Node* isBST(Tree* root){
    Node* node = new Node();

    if(root == NULL)
        return node;
    
    cout<<"ALL good "<<root->val<<endl;

    Node* left = isBST(root->left);
    Node* right = isBST(root->right);

    if(!left->isValid || !right->isValid || left->Max > root->val || right->Min <= root->val){
        
        node->size = max(left->size , right->size);
        node->isValid = 0;

        cout<<root->val <<" ends"<< endl;
        return node;
    }
    // Here BST surely exists
    node->isValid = 1;
    node->Min = (root->left) ? left->Min : root->val;
    node->Max = (root->right) ? right->Max : root->val;
    node->size = 1 + left->size + right->size;

    if(node->size > maxLen){
        maxLen = node->size;
        res = root;
    }
    
    cout<<root->val <<" finally ends"<< endl;
    return node;
    
}

Tree* solve(Tree* root) {
    res = NULL;
    maxLen = 0;

    isBST(root);

    return res;
}

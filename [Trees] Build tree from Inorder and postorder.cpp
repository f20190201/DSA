struct Node{
    int data;
    Node *left , *right;
    
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
}

int search(int inorder[] , int start , int end , int curr){
    for(int i = start ; i <= end ; i++)
        if(inorder[i] == curr)
                return i;
    return -1;
}


Node* buildTree(int postorder[] , int inorder[] , int start , int end){
    static int idx = n;   // n is the length of the array
    
    if(start > end)
        return NULL;
    
    int curr = postorder[idx];
    idx--;
    Node* node = new Node(curr);
    
    if(start == end)
        return node;
    
    int pos = search(inorder , start , end , curr);
    node->right = buildTree(postorder , inorder , pos+1 ,end);
    node->left = buildTree(postorder , inorder , start ,pos-1);
    
    
    return node;
}

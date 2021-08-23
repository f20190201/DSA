void inorderPrint(Node* root){
    
    if(root == NULL)
        return;
    
    inorderPrint(root->left);
    cout<<root->val<<" ";
    inorderPrint(root->right);
}

int index;
    
    TreeNode* solve(vector<int>& pre , vector<int>& in , int start , int end){
        
        if(start > end)
            return NULL;
    
        int curr = pre[index];
        index++;
        int pos;
        
        for(int i = start ; i <= end ; i++){
            if(in[i] == curr)
                pos = i;
        }
        
        TreeNode* root = new TreeNode(curr);
        
        root->left = solve(pre , in , start , pos - 1);
        root->right = solve(pre , in , pos + 1 , end);
        
        return root;
    }
    
    TreeNode *buildTree(vector<int> &pre, vector<int> &in) {
        index = 0;
        return solve(pre,in,0,in.size() - 1);
}

// The first element after a NULL in the level order traversal queue is the leftmost node in a level.

// https://binarysearch.com/problems/Left-Side-View-of-a-Tree

vector<int> solve(Tree* root) {
    vector<int> result;

    if(!root)
        return result;
    
    result.push_back(root->val);

    queue<Tree*> q;
    q.push(root);
    q.push(NULL);

    bool prevNULL = 0;

    while(!q.empty()){
        
        auto top = q.front();
        
        if(prevNULL){
            result.push_back(top->val);
            prevNULL = 0;
        }

        q.pop();
        
        if(top == NULL){
            if(q.empty())
                break;
            
            q.push(NULL);
            prevNULL = 1;
            continue;
        }

        if(top->left)
            q.push(top->left);
        
        if(top->right)
            q.push(top->right);
        
    }

    return result;
}

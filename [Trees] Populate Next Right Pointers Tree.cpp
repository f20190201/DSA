void Solution::connect(TreeLinkNode* A) {
    queue<TreeLinkNode*> q;

    q.push(A);
    q.push(NULL);

    while(!q.empty()){
        auto top = q.front();
        q.pop();

        if(top){
            top->next = q.front();

            if(top->left)
                q.push(top->left);

            if(top->right)
                q.push(top->right);

        }
        else{
            if(!q.empty())
                q.push(NULL);
        }

    }

    return;
}

--------------------------------------------------------------------------------
  
  

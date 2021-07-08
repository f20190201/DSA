vector<int> Solution::solve(TreeNode* A, int B) {
    queue<pair<TreeNode* , TreeNode*>>q;

    vector<int> result;

    q.push({NULL , A});

    while(!q.empty()){
        
        int sz = q.size();
        
        vector<pair<int , int>>v;
        
        while(sz--){
            auto top = q.front();
            q.pop();

            if(top.second->left){
                q.push({top.second , top.second->left});
                v.push_back({top.second->val , top.second->left->val});
            }

            if(top.second->right){
                q.push({top.second , top.second->right});
                v.push_back({top.second->val , top.second->right->val});
            }
        }
        int parent = -1;

        for(auto x : v){
            if(x.second == B){
                parent = x.first;
                break;
            }
        }

        if(parent != -1){
            for(auto x : v){
                if(x.first == parent)
                    continue;
                result.push_back(x.second);
            }
            return result;
        }

    }
    return result;
}

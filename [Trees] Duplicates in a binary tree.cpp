// We use a map to contain all the subtrees of a given tree
// We use @ as a delimiter if a particular node is NULL, in order to differentiate it.

//   2                          2
// /   \          from            \
//4     5                           4
                               //     \
map<string , int> mp;         //        5

string solve(Node* root){
    if(root == NULL)
        return "@";
    
    string s = "";
    
    
    if(root->left == NULL and root->right == NULL){
            s = to_string(root->data);
        return s;
        
    }
    
    s += to_string(root->data);
    s += solve(root->left);
    s += solve(root->right);
    
    mp[s]++;
    return s;
}

bool dupSub(Node *root)
{
     
    mp.clear();
    solve(root);
    // for(auto x:mp)
    //     cout<<x.first<<"\t"<<x.second<<endl;
    
    
    for(auto x: mp){
        if(x.second >= 2)
            return 1;
    }
    return 0;
    
}

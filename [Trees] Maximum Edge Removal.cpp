// Make a graph out of the given vector
// Proceed with DFS where the function gives the size of graph.
// If this size is even ans++ else add it to the current size
// When even, we don't add to current isze becuase we assume we can cut it off making current size 0

int DFS(map<int , vector<int>> &adj , int root , int &ans , int parent){
    
    if(adj[root].size() == 1 and adj[root][0] == parent)
        return 1;

    int size = 1;

    for(auto v : adj[root]){
        if(v == parent)
            continue;
        
        int sz = DFS(adj , v , ans , root);
        
        if(sz % 2 == 0)
            ans++;
        else
            size += sz;
    } 

    return size;
}


int Solution::solve(int A, vector<vector<int> > &B) {
    map<int , vector<int>> adj;

    for(int i = 0 ; i < B.size() ; i++){
        adj[B[i][0]].push_back(B[i][1]);
        adj[B[i][1]].push_back(B[i][0]);
    }

    int root = B[0][0];
    int ans = 0;
    int sz = DFS(adj , root , ans , -1);

    return ans;
}

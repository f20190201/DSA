bool DFS(int V , int A , vector<vector<int>> &adj , vector<bool> &visited){
    
    if(V == A)
        return 1;

    visited[V] = 1;

    for(int i = 0 ; i < adj[V].size() ; i++){
        if(!visited[adj[V][i]])
            if(DFS(adj[V][i] , A , adj , visited))
                return 1;      
    }
    
    return 0;
    

}

int Solution::solve(int A, vector<vector<int> > &B) {
    vector<bool> visited(A , 0);
    
    vector<vector<int>> adj(A + 1);
    
    for(int i = 0 ; i < B.size() ; i++)
        adj[B[i][0]].push_back(B[i][1]);
    
    return DFS(1 , A , adj , visited);
    
}

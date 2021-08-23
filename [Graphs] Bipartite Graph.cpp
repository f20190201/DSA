// https://www.youtube.com/watch?v=uC884ske2uQ

bool DFS(vector<vector<int>>& adj , vector<int>& colour , int V){
    
    if(colour[V] == -1)
        colour[V] = 1;

    for(auto it : adj[V]){
        
        if(colour[it] == -1){
            colour[it] = 1 - colour[V];
            
            if(DFS(adj , colour , it) == 0)
                return 0;
        }
        
        else{
            if(colour[it] == colour[V])
                return 0;
        }
    }
    return 1;
}

bool solve(vector<vector<int>>& graph) {
    int n = graph.size();

    vector<int> colour(n , -1);

    for(int i = 0 ; i < n ; i++){
        
        if(colour[i] == -1){
            if(DFS(graph , colour , i) == 0)
                return 0;
        }
    }

    return 1;
}

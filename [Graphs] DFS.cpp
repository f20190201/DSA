		
	void DFS(int V , vector<int> adj[] , bool visited[] , vector<int> &result){
	    
    //Marking the current node as visited
      visited[V] = 1;
	    result.push_back(V);
	    
	    vector<int> :: iterator it;
	    
    //Iterating for each neighbour of the current node and calling DFS recursively for it
	    for(it = adj[V].begin() ; it != adj[V].end() ; ++it){
	        if(!visited[*it])
	            DFS(*it , adj , visited , result);
	    }
	}
	
	vector<int>dfsOfGraph(int V, vector<int> adj[])
	{
	    // Creating a visited array to keep count of vertices visited
	    bool *visited = new bool[V];
	    for(int i = 0 ; i < V ; i++)
	        visited[i] = 0;
	    
	    vector<int> result;
	    
    //Calling DFS for each node if unvisited
	    for(int i = 0 ; i < V ; i++){
	        if(!visited[i])        
	            DFS(i , adj, visited , result);
	    }
	    
	    
	    return result;
	        
	}

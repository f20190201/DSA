//Topological sort is a method in which every parent comes before its child. 
// for Each (u , v) , u always comes before v.
// Process is, just apply post order DFS

void DFS(int V , vector<int> adj[] , vector<int> &v , bool visited[]){
	        visited[V] = 1;
	        
	        vector<int> :: iterator it;
	        
	        for(it = adj[V].begin() ; it != adj[V].end() ; ++it){
	            if(!visited[*it])
	                DFS(*it , adj , v , visited);
	        }
	    v.push_back(V);
	    return;
	}
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> v;
	    bool visited[V] = {0};
	    
	    for(int i = 0 ; i < V ; i++){
	        if(!visited[i])
	            DFS(i , adj , v , visited);
	    }
	    reverse(v.begin() , v.end());
	    return v;
	    
	}
  
  
  ----------------------------------------------------------------
  
  
  void DFS(int V , vector<int> adj[] , vector<int> &v , bool visited[]){
	    if(!visited[V]){
	        visited[V] = 1;
	        vector<int> :: iterator it;
	        for(it = adj[V].begin() ; it != adj[V].end() ; ++it){
	            DFS(*it , adj , v , visited);
	            
	        }
	    
	        v.push_back(V);
	    }
	    
	    return;
	}
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> v;
	    bool visited[V] = {0};
	    
	    for(int i = 0 ; i < V ; i++){
	        if(!visited[i])
	            DFS(i , adj , v , visited);
	    }
	    reverse(v.begin() , v.end());
	    return v;
	    
	}

bool DFS(int V , vector<int> adj[] , bool visited[] , bool s[]){
	    if(!visited[V]){
	        visited[V] = 1;
	        s[V] = 1;
	        
	        vector<int> :: iterator it;
	        
	        for(it = adj[V].begin() ; it != adj[V].end() ; ++it){
	            if(!visited[*it] and DFS(*it , adj , visited , s))
	                return 1;
	            
	            else if(s[*it])
	                return 1;
	        }
	    }
	    s[V] = 0;
	    return 0;
	    
	}
	
	bool isCyclic(int V, vector<int> adj[]) 
	{
	   	// code here
	   	bool *visited = new bool[V];
	   	bool *s = new bool[V];
	   	for(int i = 0 ; i < V ; i++){
	   	    visited[i] = 0;
	   	    s[i] = 0;
	   	}
	   	
	   	
	   	
	   	for(int i = 0 ; i < V ; i++){
	   	    if(DFS(i , adj , visited , s))
	   	        return 1;
	   	  
	   	}
	    return 0;
	   	
	}

bool cycle_finder(int V , bool visited[] , vector<int>adj[], int parent){
	    
	        visited[V] = 1;
	        vector<int> :: iterator it;
	        
	        for(it = adj[V].begin() ; it != adj[V].end() ; ++it){
	            if(!visited[*it]){
	                if (cycle_finder(*it , visited , adj , V))
	                return 1;
	                
	            }
	            
	            else if(*it != parent)
	            return 1;
	            
	        }
	   
	   return 0;
	}
	
	
	bool isCycle(int V, vector<int>adj[])
	{
	    // Code here
	    bool *visited = new bool[V];
	    for(int i = 0 ; i < V ; i++)
	        visited[i] = 0;
	    bool flag = 0;
	    
	    for(int i = 0 ; i < V ; i++){
	        if(!visited[i])
	            if(cycle_finder(i , visited , adj , -1))
	                return 1;
	        
	    }
	    
	    return 0;
	    
	}

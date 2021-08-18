// A curr_visited array keeps track of nodes that are visited in one DFS call itself.

// https://www.youtube.com/watch?v=uzVUw90ZFIg&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=12

bool solve(vector<int> adj[] , int V , int visited[] , int curr_visited[]){
	    
	    visited[V] = 1;
	    curr_visited[V] = 1;
	    
	    for(int child : adj[V]){
	        
	        if(visited[child] == 1){
	            
	            if(curr_visited[child] == 1)
	                return 1;
	            
	            continue;
	        }
	        
	        if(solve(adj , child , visited , curr_visited) == 1)
	            return 1;
	    }
	    
	    curr_visited[V] = 0;
	    return 0;
	}
	
	bool isCyclic(int V, vector<int> adj[]) 
	{
	   	// code here
	   	int visited[V] , curr_visited[V];
	   	
	   	memset(visited , 0 , sizeof(visited));
	   	memset(curr_visited , 0 , sizeof(curr_visited));
	   	
	   	for(int i = 0 ; i < V ; i++){
	   	    if(!visited[i])
	   	        if(solve(adj , i , visited , curr_visited))
	   	            return 1;
	   	}
	   	
	   	return 0;
	}

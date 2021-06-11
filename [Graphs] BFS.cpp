vector<int>bfsOfGraph(int V, vector<int> adj[])
	{
	  
	    vector<int> result;
	    
   //Making a queue to store the nodes visited
      list<int> q;
	    
	    bool* visited = new bool[V];
	    for(int i = 0 ; i < V ; i++)
	        visited[i] = 0;
	  //Pushing the first node into the queue  
	    visited[0] = 1;
	    q.push_back(0);
	    vector<int> :: iterator it;

  // Similar to the level order traversal in trees
	    while(!q.empty()){
	        int curr = q.front();
	        result.push_back(curr);
	        q.pop_front();
	        
	        for(it = adj[curr].begin() ; it != adj[curr].end() ; ++it){
	            if(!visited[*it]){
	                visited[*it] = 1;
	                q.push_back(*it);
	            }
	        }
	    }
	    
	    
	    
	 
	    return result;
	}

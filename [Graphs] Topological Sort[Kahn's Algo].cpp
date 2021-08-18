// Make an inDegree array that keeps count of incoming edges into that node
// If value of a node in inDegree array is 0, push it into the queue
// Add it to result array when popping from queue
// Reduce values of all adjacent vertices of q.front() by 1, basically reduce dependency of neighbours by 1
// Repeat from step 2 till q becomes empty

vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> inDegree(V , 0);
	    
	    for(int i = 0 ; i < V ; i++){
	        for(auto child : adj[i])
	            inDegree[child]++;
	    }
	    
	    queue<int>q;
	    vector<int> result;
	    
	    for(int i = 0 ; i < V ; i++){
	        
	        int x = inDegree[i];
	        
	        if(x == 0)
	            q.push(i);
	        
	    }
	    
	    while(!q.empty()){
	        auto top = q.front();
	        q.pop();
	        
	        result.push_back(top);
	        
	        for(auto child : adj[top]){
	            
	            inDegree[child]--;
	            
	            if(inDegree[child] == 0)
	                q.push(child);
	        }
	    }
	    
	    return result;
	}

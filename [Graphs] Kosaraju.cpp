// Run a post order DFS 
// Store the post order DFS in a vector called the order vector
// Reverse the graph
// Iterate the vector from the end, like topological sort
// Run a DFS for reversed graph in the order of 4th point
// Number of strongly connected components is the number of times DFS is called in iterating the reversed graph

class Solution
{
	public:
	vector<int>v;
	
	//Function to find number of strongly connected components in the graph.
	void postOrderDFS(int V , vector<int> adj[] , bool visited[]){
	    if(!visited[V]){
	        visited[V] = 1;
	        
	        vector<int> :: iterator it;
	        for(it = adj[V].begin() ; it != adj[V].end() ; ++it){
	            if(!visited[*it])
	                postOrderDFS(*it , adj , visited);
	        }
        // Store the post order DFS in a vector called the order vector
	        v.push_back(V);
	    }
	}
	
	
	void newDFS(int V , vector<int> adj[] , bool visited[]){
	    if(!visited[V]){
	        visited[V] = 1;
	        
	        vector<int> :: iterator it;
	        
	        for(it = adj[V].begin() ; it != adj[V].end() ; ++it){
	            if(!visited[*it])
	                newDFS(*it , adj , visited);
	        }
	    }
	}
	
    int kosaraju(int V, vector<int> adj[])
    {
        //code here
        vector<int> rev[V];
        v.clear();
        int result = 0;
        
        for(int i = 0 ; i < V ; i++){
	        
	        vector<int> :: iterator it;
	   // Reverse the graph 
	        for(it = adj[i].begin() ; it != adj[i].end() ; ++it){
	            rev[*it].push_back(i);  
	        }
	    }
        
        
        bool visited[V] = {0};

      // Run a post order DFS  
      
        for(int i = 0 ; i < V ; i++){
            if(!visited[i])
                postOrderDFS(i , adj , visited);
        }
        
        memset(visited , 0 , sizeof(visited));

      // Iterate the vector from the end, like topological sort
      
        for(int i = v.size() - 1 ; i >= 0 ; i--){
  
   // Run a DFS for reversed graph in the order of reversed order vector
            if(!visited[v[i]]){
                newDFS(v[i] , rev , visited);
              
   // Number of strongly connected components is the number of times DFS is called in iterating the reversed graph
                result++;
            }
        }
        return result;
    }
};

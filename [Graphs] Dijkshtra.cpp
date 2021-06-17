// Make a minHeap that stores {weight,vertex} 
// dist vector stores distance of all nodes from the source. Initialised to INF for all nodes except source and initialised to 0 for source
// Push source into minHeap and a]make its distance 0
// Loop while(minHeap.size() != 0)
// Pop from minHeap and check for all its adjacent vertices
// While checking, if dist[v] > dist[u] + weight(u,v) then update dist[v] = dist[u] + weight(u,v) and push this into the minHeap

class Solution
{   
	public:
	# define INF 0x3f3f3f3f
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<int> result(V);
        for(int i = 0 ; i < V ; i++){
            if(i == S)
                result[i] = 0;
            else
                result[i] = INF;
        }
        
        
            
        
        priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>> minHeap;
        
        minHeap.push({0 , S});
       
        
        while(minHeap.size() != 0){
            auto node = minHeap.top();
            minHeap.pop();
            int curr_weight = node.first;
            int curr_node = node.second;
            
            vector<vector<int>> :: iterator it;
            
            for(it = adj[curr_node].begin() ; it != adj[curr_node].end() ; ++it){
                if(result[(*it)[0]] > (result[curr_node] + (*it)[1])){
                    result[(*it)[0]] = (result[curr_node] + (*it)[1]);
                    minHeap.push({result[(*it)[0]] , (*it)[0]});
                }
                    
                }    
            }
        return result;
    }
};

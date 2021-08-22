// Idea is to match each word with its next
// The mismatched letters are converted into a graph
// Topological order of this graph gives us the answer
// This method works because in toposort, always u comes before v (u -> v) and our graph also creates an edge in the corresponding way

void topoSort(vector<vector<int>>& adj , vector<bool>& visited , int V , string& res){
        visited[V] = 1;
        
        for(auto it : adj[V]){
            
            if(!visited[it])
                topoSort(adj , visited , it , res);    
        }
        
        res.push_back((char)(V + 'a'));
        return;
    }
    
    string findOrder(string dict[], int N, int K) {
        //code here
        vector<vector<int>>adj(K);
        
        for(int i = 0 ; i < N - 1 ; i++){
            string word1 = dict[i] , word2 = dict[i + 1];
            
            for(int j = 0 ; j < min(word1.size() , word2.size()) ; j++){
                
                if(word1[j] != word2[j]){
                    
                    adj[word1[j] - 'a'].push_back(word2[j] - 'a');
                    break;
                }
            }
        }
        
        string res = "";
        vector<bool> visited(26 , 0);
        
        for(int i = 0 ; i < K ; i++){
            if(!visited[i])
                topoSort(adj , visited , i , res);
        }
        
        reverse(res.begin() , res.end());
        
        // cout<<res<<endl;
        
        return res;
    }

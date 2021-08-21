// Make a time array where each element is initialised to -1
// Iterate through the array once and make t[i][j] = 0 for A[i][j] = 2 and push this coordinate along with t[i][j] into the queue(for BFS)
// Loop until the queue is empty and when we see an unvisited(t[i][j] == -1) 1, push it into the queue with time of infection 1 more than the current

    int dx[4] = {1 , -1 , 0 , 0};
    int dy[4] = {0 , 0 , 1 , -1};
    
    bool isValid(vector<vector<int>>& A , vector<vector<int>>& t , int i , int j){
        int n = A.size() , m = A[0].size();
        
        return (i >= 0 && i < n && j >= 0 && j < m && A[i][j] && t[i][j] == -1);
    }
    
    int helpaterp(vector<vector<int>> A)
    {
        //code here
     
        int n = A.size() , m = A[0].size();
        
        vector<vector<int>> t(n , vector<int>(m , -1));
        
        queue<pair<pair<int, int>, int> > q;
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                
                if(A[i][j] == 2){
                    q.push({ { i, j }, 0 });
                    t[i][j] = 0;
                }
            }
        }
        
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            
            for(int k = 0 ; k < 4 ; k++){
                
                int i = curr.first.first + dx[k];
                int j = curr.first.second + dy[k];
                
                if(isValid(A , t , i , j)){
                    q.push({{i , j} , curr.second + 1});
                    t[i][j] = curr.second + 1;
                }
            }
        }
        
        int ans = INT_MIN;
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                
                if(A[i][j] == 1 && t[i][j] == -1)
                    return -1;
                    
                if(A[i][j] == 1)
                    ans = max(ans , t[i][j]);
            }
        }
        return ans;
    }

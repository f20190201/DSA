class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>> &A) {
        int m = A.size() , n = A[0].size(); 
        if(A[0][0])
            return 0;
        
        int dist[m][n];
        
        // bool flag = 0;
        
        dist[0][0] = 1;
        
        for(int j = 1 ; j < n ; j++){
            
            if(A[0][j] == 1)
                dist[0][j] = 0;
            
            else
                dist[0][j] = dist[0][j - 1];
        }
        
        for(int i = 1 ; i < m ; i++){
            
            if(A[i][0] == 1)
                dist[i][0] = 0;
            
            else
                dist[i][0] = dist[i - 1][0];
            
        }
        
        
        for(int i = 1 ; i < m ; i++){
            for(int j = 1 ; j < n ; j++){
                
                if(A[i][j] == 1)
                    dist[i][j] = 0;
                
                else
                    dist[i][j] = dist[i][j - 1] + dist[i - 1][j];
            }
        }
        return dist[m - 1][n - 1];
    }
};
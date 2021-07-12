class Solution {
public:
    
    
    int minPathSum(vector<vector<int>>& grid) {
        
        int m = grid.size() , n = grid[0].size();
        
        int dist[m][n];
        dist[0][0] = grid[0][0];
        
        for(int i = 1 ; i < m ; i++)
            dist[i][0] = grid[i][0] + dist[i - 1][0];
        
        for(int j = 1 ; j < n ; j++)
            dist[0][j] = grid[0][j] + dist[0][j - 1];
        
        for(int i = 1 ; i < m ; i++){
            for(int j = 1 ; j < n ; j++)
                dist[i][j] = (min(dist[i - 1][j] , dist[i][j - 1]) + grid[i][j]);
        }
        
        return dist[m - 1][n - 1];
    }
};
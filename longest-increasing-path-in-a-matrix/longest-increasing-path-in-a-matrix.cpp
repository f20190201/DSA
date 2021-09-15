class Solution {
public:
    int ans;
    
    int dp[201][201];
    
    int DFS(vector<vector<int>>& matrix , int i , int j){
        
        int n = matrix.size() , m = matrix[0].size();    
        
        int curr = matrix[i][j];
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int left = 0 , up = 0 , down = 0 , right = 0;
        
        if(i > 0)
            if(matrix[i - 1][j] > curr)
                up = 1 + DFS(matrix , i - 1 , j);
        
        if(i < n - 1)
            if(matrix[i + 1][j] > curr)
                down = 1 + DFS(matrix , i + 1 , j);
        
        if(j > 0)
            if(matrix[i][j - 1] > curr)
                left = 1 + DFS(matrix , i , j - 1);
        
        if(j < m - 1)
            if(matrix[i][j + 1] > curr)
                right = 1 + DFS(matrix , i , j + 1);
        
        int maxVal = max({left , right , up, down});
        
        return dp[i][j] = maxVal;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        ans = 0;
        memset(dp , -1 , sizeof(dp));
        
        int n = matrix.size() , m = matrix[0].size();
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                
                ans = max(ans , 1 + DFS(matrix , i , j));
            }
        }
        
        return ans;
    }
};
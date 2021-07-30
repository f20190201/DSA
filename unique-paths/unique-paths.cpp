class Solution {
public:
    int dp[101][101];
    
    bool isValid(int m , int n , int i , int j){
        return (i < m && j < n && i >= 0 && j >= 0);
    }
    
    int solve(int m , int n , int i , int j){
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int count = 0;
        
        if(i == m - 1 && j == n - 1){
            count = 1;
            return dp[i][j] = count;
        }
        
        if(isValid(m , n , i + 1 , j))
            count += solve(m , n , i + 1 , j);
        
        if(isValid(m , n , i , j + 1))
            count += solve(m , n , i , j + 1);
        
        return dp[i][j] = count;
    }
    
    int uniquePaths(int m, int n) {
        memset(dp , -1 , sizeof(dp));
        int count = 0;
        
        return solve(m , n , 0 , 0);
        
    }
};
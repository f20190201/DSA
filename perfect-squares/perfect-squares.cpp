class Solution {
public:
    int numSquares(int n) {
        int num = sqrt(n) + 1;
        
        int dp[num + 1][n + 1];
        memset(dp , 0 , sizeof(dp));
        
        for(int j = 0 ; j <= n ; j++)
            dp[0][j] = INT_MAX/10;
        
        dp[0][0] = 1;
        
        for(int i = 1 ; i <= num ; i++){
            for(int j = 1 ; j <= n ; j++){
                
                if(j >= i * i)
                    dp[i][j] = min(1 + dp[i][j - i * i] , dp[i - 1][j]);
                
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[num][n];
    }
};
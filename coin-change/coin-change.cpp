class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        
        
        int dp[n + 1][amount + 1];
        memset(dp , 0 , sizeof(dp));
        
        for(int i = 0 ; i <= n ; i++)
            dp[i][0] = 0;
        
        for(int j = 1 ; j <= amount ; j++){
            dp[0][j] = INT_MAX - 1;
            
            dp[1][j] = (j % coins[0] == 0) ? (j / coins[0]) : INT_MAX - 1;
            
        }
        
        for(int i = 2 ; i <= n ; i++){
            for(int j = 1 ; j <= amount ; j++){
                
                if(coins[i - 1] <= j)
                    dp[i][j] = min(1 + dp[i][j - coins[i - 1]] , dp[i - 1][j]);
                
                else
                    dp[i][j] = dp[i - 1][j];
                
            }
        }
        
        if(dp[n][amount] == INT_MAX - 1)
            return -1;
        
        return dp[n][amount];
    }
};
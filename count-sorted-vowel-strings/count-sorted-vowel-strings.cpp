class Solution {
public:
    int countVowelStrings(int n) {
        int dp[n + 1][5];   //a - 0 , e - 1 , i - 2 , o - 3 , u - 4 
        
        memset(dp , 0 , sizeof(dp));
        
        for(int j = 0 ; j <= 4 ; j++){
            dp[1][j] = 1;
        }
        
        for(int i = 2 ; i <= n ; i++){
            for(int j = 0 ; j <= 4 ; j++){
                
                for(int k = 0 ; k <= j ; k++){
                    dp[i][j] += dp[i - 1][k];
                    
                } 
                
            }
        }
        
        return (dp[n][0] + dp[n][1] + dp[n][2] + dp[n][3] + dp[n][4]);
        
    }
};
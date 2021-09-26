class Solution {
public:
    int countSubstrings(string s, string t) {
        int n = s.size() , m = t.size();
        int dp[n][m][2];
        
        int ans = 0;
        
        memset(dp , 0 , sizeof(dp));
        
        for(int i = 0  ; i < n ; i++){
            
            if(s[i] == t[0]){
                
                dp[i][0][0] = 1;
                dp[i][0][1] = 0;
                
            }
            else{
                dp[i][0][0] = 0;
                dp[i][0][1] = 1;
            }
            
            ans += dp[i][0][1];
        }
        
        for(int j = 1 ; j < m ; j++){
            
            if(s[0] == t[j]){
                
                dp[0][j][0] = 1;
                dp[0][j][1] = 0;
                
            }
            else{
                dp[0][j][0] = 0;
                dp[0][j][1] = 1;
            } 
            ans += dp[0][j][1];
        }
        
        for(int i = 1 ; i < n ; i++){
            for(int j = 1 ; j < m ; j++){
                
                if(s[i] == t[j]){
                    dp[i][j][0] = 1 + dp[i - 1][j - 1][0];
                    dp[i][j][1] = dp[i - 1][j - 1][1];
                }
                
                else{
                    dp[i][j][0] = 0;
                    dp[i][j][1] = 1 + dp[i - 1][j - 1][0];
                }
                
                ans += dp[i][j][1];
            }
        }
        
        return ans;
    }
};
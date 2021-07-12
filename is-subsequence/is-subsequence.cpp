class Solution {
public:
    
    bool isSubsequence(string s, string t) {
       
        int n1 = s.size() , n2 = t.size();
        
        if(!n1)
            return 1;
        
        int dp[n1 + 1][n2 + 1];
        memset(dp , 0 , sizeof(dp));
        
        for(int i = 1 ; i <= n1 ; i++){
            
            for(int j = 1 ; j <= n2 ; j++){
                
                if(s[i - 1] == t[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                
                else
                    dp[i][j] = max(dp[i - 1][j] , dp[i][j - 1]);
            }
        }
        
        int LCS = dp[n1][n2];
        
        return (LCS == s.size());
        
    }
};
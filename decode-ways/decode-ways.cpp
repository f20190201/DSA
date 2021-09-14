class Solution {
public:
    int numDecodings(string s) {
        int n = s.size() , dp[n + 1];
        
        if(s[0] == '0')
            return 0;
        
        memset(dp , 0 , sizeof(dp));
        
        if(s[0] == '0')
            dp[0] = 0;
        else
            dp[0] = 1;
        
        if(n == 1)
            return dp[0];
        
        if(s[1] == '0')
            dp[1] = (s[0] == '1' || s[0] == '2');
        else
            dp[1] = stoi(s.substr(0 , 2)) <= 26 ? 2 : dp[0];
        
        for(int i = 2 ; i < n ; i++){
            
            if(s[i] == '0' && s[i - 1] == '0')
                dp[i] = 0;
            
            else if(s[i] != '0' && s[i - 1] == '0')
                dp[i] = dp[i - 1];
            
            else if(s[i] == '0' && s[i - 1] != '0')
                dp[i] = (s[i - 1] == '1' || s[i - 1] == '2') ? dp[i - 2] : 0;
            
            else{
                dp[i] = dp[i - 1];
                
                if(stoi(s.substr(i - 1 , 2)) <= 26)
                    dp[i] += dp[i - 2];
            }
        }
        return dp[n - 1];
    }
};
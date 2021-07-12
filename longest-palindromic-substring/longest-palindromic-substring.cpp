class Solution {
public:
    
    string longestPalindrome(string s) {
        int n = s.size();
        
        
        int dp[n][n] , maxLen = 0 , start = 0;
        
        for(int i = n - 1 ; i >= 0 ; i--){
            
            for(int j = i ; j < n ; j++){
                
                dp[i][j] = (s[i] == s[j]) and ((j - i + 1 <= 2) or dp[i + 1][j - 1]);
                
                if(dp[i][j]){
                    
                    if(j - i + 1 > maxLen){
                        maxLen = j - i + 1;
                        start = i;
                    }
                    
                }
            }
        }
        return s.substr(start , maxLen);
    }
};
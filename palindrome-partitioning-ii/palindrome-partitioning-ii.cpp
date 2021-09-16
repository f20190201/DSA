class Solution {
public:
    
    
    
    int minCut(string s) {
        
        int size = s.size();
        vector<int> dp(size+1, 0);

        for(int i = 0; i <= size; i++) 
            dp[i] = i-1;
 
        for(int i = 0; i < size; i++) {
            
            // odd length palindrome
            for(int j = 0; i-j >= 0 && i+j < size && s[i+j] == s[i-j];j++)
                dp[i+j+1] = min(dp[i+j+1], dp[i-j]+1);

            // even length palindrome
            for(int j = 0; i-j-1 >= 0 && i+j < size && s[i+j] == s[i-j-1]; j++)
                dp[i+j+1] = min(dp[i+j+1], dp[i-j-1]+1);
        }
        
        return dp[size];
    }
};
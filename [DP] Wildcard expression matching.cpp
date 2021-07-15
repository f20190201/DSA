int Solution::isMatch(const string text , const string pattern) {
    int n = text.size() , m = pattern.size();
    if(m == 0)
        return (n == 0);
    
    vector<vector<bool>>dp(n + 1 , vector<bool>(m + 1 , 0));

    // long long int dp[n + 1][m + 1];
    // memset(dp , 0 , sizeof(dp));

    dp[0][0] = 1;
    
    for(int j = 1 ; j <= m ; j++)
        if(pattern[j - 1] == '*')
            dp[0][j] = dp[0][j - 1];
    
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){

            if(pattern[j - 1] == '?' or (pattern[j - 1] == text[i - 1]))
                dp[i][j] = dp[i - 1][j - 1];

            else if(pattern[j - 1] == '*')
                dp[i][j] = (dp[i - 1][j] or dp[i][j - 1]);
            
            else
                dp[i][j] = 0;

        }


    }
    return dp[n][m];
}

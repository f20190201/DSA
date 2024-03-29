// https://www.youtube.com/watch?v=l3hda49XcDE

int Solution::isMatch(const string text, const string pattern) {
    int n = text.size() , m = pattern.size();

    vector<vector<bool>>dp(n + 1 , vector<bool>(m + 1 , 0));

    dp[0][0] = 1;

    for(int j = 1 ; j <= m  ; j++)
        if(pattern[j - 1] == '*')
            dp[0][j] = dp[0][j - 2];
    
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){

            if(pattern[j - 1] == '.' or (text[i - 1] == pattern[j - 1]))
                dp[i][j] = dp[i - 1][j - 1];
            
            else if(pattern[j - 1] == '*'){
                dp[i][j] = dp[i][j - 2];

                if(pattern[j - 2] == text[i - 1] or pattern[j - 2] == '.')
                    dp[i][j] = dp[i][j] or dp[i - 1][j];
            }

            else
                dp[i][j] = 0;

        }

    }
    return dp[n][m];
}

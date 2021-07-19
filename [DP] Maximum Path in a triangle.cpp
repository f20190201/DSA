int Solution::solve(vector<vector<int> > &A) {
    int n = A.size();
    int dp[n + 1][n + 1];
    memset(dp , 0 , sizeof(dp));
    int res = INT_MIN;

    dp[0][0] = A[0][0];

    if(n == 1)
        return A[0][0];

    for(int i = 1 ; i < n ; i++){
        for(int j = 0 ; j <= i ; j++){
            
            if(j == 0)
                dp[i][j] = A[i][j] + dp[i - 1][j];
            else
                dp[i][j] = A[i][j] + max(dp[i - 1][j] , dp[i - 1][j - 1]);
            res = max(res , dp[i][j]);
        }
    }
    return res;
}

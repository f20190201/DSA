// https://www.youtube.com/watch?v=4uUGxZXoR5o

int Solution::calculateMinimumHP(vector<vector<int> > &A) {
    int n = A.size() , m = A[0].size();

    int dp[n][m];
    dp[n - 1][m - 1] = min(0 , A[n - 1][m - 1]);
    for(int i = n - 1 ; i >= 0 ; i--){
        for(int j = m - 1 ; j >= 0 ; j--){
            
            if(i == (n - 1) and j == (m - 1))
                continue;

            if(i < n - 1 and j < m - 1)
                dp[i][j] = min(0 , A[i][j] + max(dp[i + 1][j] , dp[i][j + 1]));
            
            else if (i < n - 1)
                dp[i][j] = min(0 , A[i][j] + dp[i + 1][j]);
            
            else
                dp[i][j] = min(0 , A[i][j] + dp[i][j + 1]);
            
        }
    }

    if(dp[0][0] > 0)
        return 1;
    
    return (1 - dp[0][0]);

}

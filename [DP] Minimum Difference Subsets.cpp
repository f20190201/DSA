// A variation of 0-1 knapsack since S1 + S2 is known and we need to reduce S1 - S2

int Solution::solve(vector<int> &A) {
    int sum = 0 , n = A.size();

    for(auto x : A)
        sum += x;
    
    int wt = sum;

    int dp[n + 1][wt + 1];

    for(int i = 0 ; i <= n ; i++)
        dp[i][0] = 0;
    
    for(int j = 0 ; j <= wt ; j++)
        dp[0][j] = 0;

    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= wt ; j++){

            if(A[i - 1] <= j)
                dp[i][j] = max(A[i - 1] + dp[i - 1][j - A[i - 1]] , dp[i - 1][j]);
            
            else
                dp[i][j] = dp[i - 1][j];
        }

    }
    int ans = INT_MAX;

    for(int j = 0 ; j <= wt ; j++){
        ans = min(ans , abs(dp[n][j] - (sum - dp[n][j])));

    }

    return ans;
    
}

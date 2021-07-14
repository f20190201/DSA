// https://www.youtube.com/watch?v=Pw6lrYANjz4

int Solution::solve(vector<int> &A, int B) {
    int n = A.size();

    if(B > n / 2)
        B = n / 2;

    int dp[B + 1][n + 1];
    memset(dp , 0 , sizeof(dp));

    for(int i = 1 ; i <= B ; i++){
        for(int j = 1 ; j <= n ; j++){
            
            int profit = INT_MIN;

            for(int k = 0 ; k < j ; k++)  
                profit = max(profit , -A[k] + dp[i - 1][k]);

            dp[i][j] = max(dp[i][j - 1] , A[j - 1] + profit);
        }
    }

    int result = 0;

    for(int i = 0 ; i <= B ; i++)
        result = max(result , dp[i][n]);
    
    return result;
}

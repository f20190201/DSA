// https://www.youtube.com/watch?v=r9W4f5UyMMM

// Since the 2D array is row and column sorted, our task is to find the amsximum sum subarray
// The subarray would always include the last element since it is the largest

int Solution::solve(vector<vector<int> > &A) {
    int n = A.size() , m = A[0].size();
    int dp[n + 1][m + 1];
    memset(dp , 0 , sizeof(dp));

    int res = INT_MIN;

    for(int i = n - 1 ; i >= 0 ; i--){
        for(int j = m - 1 ; j >= 0 ; j--){

            dp[i][j] = A[i][j] + (dp[i + 1][j] + dp[i][j + 1] - dp[i + 1][j + 1]);

            res = max(res , dp[i][j]);
        }

    }

    return res;
}

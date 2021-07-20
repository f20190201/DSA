// Start from the bottom. Let the dp table store minimum sum paths from each index of every row
// dp[0] would give us the answer

int Solution::minimumTotal(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n = A.size();
    
    int dp[n];

    for(int j = 0 ; j < A[n - 1].size() ; j++)
        dp[j] = A[n - 1][j];
    
    for(int i = n - 2 ; i >= 0 ; i--){
        for(int j = 0 ; j < A[i].size() ; j++){

            dp[j] = A[i][j] + min(dp[j] , dp[j + 1]); 
        }
    }
    return dp[0];
}

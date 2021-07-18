// https://www.youtube.com/watch?v=jFZmBQ569So

#define M 1000000007
int Solution::numDecodings(string A) {
    #define int long long int
    int n = A.size();
    int dp[n];
    memset(dp , 0 , sizeof(dp));

    if(A[0] == '0')
        dp[0] = 0;
    else
        dp[0] = 1;
    
    for(int i = 1 ; i < n ; i++){
        
        if(A[i - 1] == '0' and A[i] == '0')
            dp[i] = 0;

        else if(A[i - 1] == '0' and A[i] != '0')
            dp[i] = dp[i - 1]%M;

        else if(A[i - 1] != '0' and A[i] == '0')
            dp[i] = (A[i - 1] == '1' or A[i - 1] == '2') ? ((i >= 2) ? dp[i - 2]%M : 1) : 0;
        else
            dp[i] = (stoll(A.substr(i - 1 , 2)) <= 26) ? (dp[i - 1]%M + ((i >= 2) ? dp[i - 2]%M : 1)) : dp[i - 1]%M;

    }

    return dp[n - 1]%M;
}

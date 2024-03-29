int Solution::solve(vector<vector<int> > &A) {
    int n = A.size();
    int i = 1;

    for(; i < n ; i++){

        A[i][0] += min(A[i - 1][1] , A[i - 1][2]);
        A[i][1] += min(A[i - 1][0] , A[i - 1][2]);
        A[i][2] += min(A[i - 1][0] , A[i - 1][1]); 
    }

    return min(A[i - 1][0] , min(A[i - 1][1] , A[i - 1][2]));
}



--------------------------------------------------------------------------------------------------------------------------------------------

  
  
int Solution::solve(vector<vector<int> > &A) {

int n =A.size(),m=A[0].size();
int dp[n][m];

memset(dp,0,sizeof(dp));

for(int i=0;i<n;i++)
{
    for(int j=0;j<m;j++)
    {
        if(i==0)
        dp[i][j]=A[i][j];
        
        else if(j==0)
        {
            dp[i][j]=A[i][j]+min(dp[i-1][j+1],dp[i-1][j+2]);
        }
        else if(j==m-1)
        {
            dp[i][j]=A[i][j]+min(dp[i-1][j-1],dp[i-1][j-2]);
        }
        else
        {
            dp[i][j]=min(dp[i-1][j-1],dp[i-1][j+1])+A[i][j];
        }
    }
}
int ans=INT_MAX;

for(int j=0;j<m;j++)
ans=min(ans,dp[n-1][j]);

return ans;

}


vector<vector<int> > Solution::solve(int A, vector<vector<int> > &B) {

    int rows = B.size() , cols = B[0].size();

    if(!rows or !cols)
        return {};
    
    if(!A)
        return B;

    int dp[rows][cols][A + 1];
    memset(dp , 0 , sizeof(dp));

    for(int i = 0 ; i < rows ; i++)
        for(int j = 0 ; j < cols ; j++)
            dp[i][j][0] = B[i][j];
    
    for(int k = 1 ; k <= A ; k++){
        for(int i = 0 ; i < rows ; i++){
            for(int j = 0 ; j < cols ; j++){
                
                dp[i][j][k] = dp[i][j][k - 1];

                if(i > 0)
                    dp[i][j][k] = max(dp[i][j][k] , dp[i - 1][j][k - 1]);
                
                if(i < rows - 1)
                    dp[i][j][k] = max(dp[i][j][k] , dp[i + 1][j][k - 1]);
                
                if(j > 0)
                    dp[i][j][k] = max(dp[i][j][k] , dp[i][j - 1][k - 1]);
                
                if(j < cols - 1)
                    dp[i][j][k] = max(dp[i][j][k] , dp[i][j + 1][k - 1]);


            }

        }
    }

    vector<vector<int>> ans;

    for(int i = 0 ; i < rows ; i++){
        vector<int> temp;

        for(int j = 0 ; j < cols ; j++)
            temp.push_back(dp[i][j][A]);

        ans.push_back(temp);

    }

    return ans;
}

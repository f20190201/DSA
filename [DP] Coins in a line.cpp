int dp[500][500][2];

// This solution is based on the Minimax algorithm
int solve(vector<int> &a, int i, int j, bool myturn)   {
    if (i+1 == j)   // base case, only 2 elements are left
        return max(a[i], a[j]); // turn will always be mine (why?), so i choose the max out of two
    if (dp[i][j][myturn] != -1)
        return dp[i][j][myturn];

    if (myturn)     // my turn, add the coin value to the answer, and choose max
        return dp[i][j][myturn] = max(a[i] + solve(a, i+1, j, 0),   // choosing i'th coin
                                      a[j] + solve(a, i, j-1, 0));  // choosing j'th coin
    else    // opponent's turn, don't add coin value, and choose minimum outcome
        return dp[i][j][myturn] = min(solve(a, i+1, j, 1),  // opponent chooses i'th coin
                                      solve(a, i, j-1, 1)); // opponent chooses j'th coin
}

int Solution::maxcoin(vector<int> &ar) {
    memset(dp, -1, sizeof(dp));
    return solve(ar, 0, ar.size()-1, 1);
}


---------------------------------------------------------------------------------------------------------
 // https://www.youtube.com/watch?v=ww4V7vRIzSk&t=251s 
  
  int Solution::maxcoin(vector<int> &A) {
    int n = A.size();
    int dp[n][n];

    for(int gap = 0 ; gap < n ; gap++){
        for(int i = 0 , j = gap ; j < n ; i++ , j++){

            if(gap == 0)
                dp[i][j] = A[i];
            
            else if (gap == 1)
                dp[i][j] = max(A[i] , A[j]);
            
            else
                dp[i][j] = max(A[i] + min(dp[i + 2][j] , dp[i + 1][j - 1]) , A[j] + min(dp[i][j - 2] , dp[i + 1][j - 1]));

        }

    }
    return dp[0][n - 1];
}


--------------------------------------------------------------------------------------------------------------------------
    
    
int dp[501][501];

int solve(vector<int> &A , int i , int j){
    if(i > j)
        return 0;
    
    if(dp[i][j] != -1)
        return dp[i][j];
    
    if(i == j)
        return dp[i][j] = A[i];
    
    return dp[i][j] = max(A[i] + min(solve(A , i + 2 , j) ,solve(A , i + 1 , j - 1) ) , A[j] + min(solve(A , i , j - 2) , solve(A , i + 1 , j - 1)));
}

int Solution::maxcoin(vector<int> &A) {
    int n = A.size();

    memset(dp , -1 , sizeof(dp));
    
    return solve(A , 0 , n - 1);
}

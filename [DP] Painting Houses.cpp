// https://binarysearch.com/problems/Painting-Houses
// https://www.youtube.com/watch?v=jGywRalvoRw

int minVal(int arr[] , int j , int k){
    int ans = INT_MAX;

    for(int i = 0 ; i < k ; i++){
        if(i == j)
            continue;
        ans = min(ans , arr[i]);
    }
        
    return ans;
}

int solve(vector<vector<int>>& matrix) {
    int n = matrix.size() , k = matrix[0].size();
    
    int dp[n][k];

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < k ; j++)
            dp[i][j] = INT_MAX / 10;
    }

    for(int j = 0 ; j < k ; j++){
        dp[0][j] = matrix[0][j];
    }

    for(int i = 1 ; i < n ; i++){

        for(int j = 0 ; j < k ; j++){
            dp[i][j] = matrix[i][j] + minVal(dp[i - 1] , j , k);
        }
    }

    int ans = INT_MAX;

    for(int j = 0 ; j < k ; j++)
        ans = min(ans , dp[n - 1][j]);
    
    return ans;
}

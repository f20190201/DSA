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


---------------------
  // Slow, runs in O(N K^2)  
    
    int n;
void minCost(vector<vector<int>>& matrix , int fence , int curr_choice , int &ans , int temp){
    int k = matrix[0].size();

    if(fence == n){
        ans = min(ans , temp);
        return;
    }
    
    for(int price = 0 ; price < k ; price++){
        if(price == curr_choice)
            continue;
        
        temp += matrix[fence][price];
        minCost(matrix , fence + 1 , price , ans , temp);
        temp -= matrix[fence][price];
    }
    
    return;
}

int solve(vector<vector<int>>& matrix) {
    int ans = INT_MAX , temp = 0;
    n = matrix.size();
    int k = matrix[0].size();

    for(int j = 0 ; j < k ; j++){
        temp += matrix[0][j];
        minCost(matrix , 1 , j , ans , temp);
        temp -= matrix[0][j];
    }

    return ans;
}

int Solution::numDistinct(string A, string B) {
    int n = A.size() , m = B.size();

    vector<vector<int>> t(m + 1 , vector<int>(n + 1 , 0));

    for(int i = 1 ; i <= n ; i++){
        if(B[0] == A[i - 1])
            t[1][i] = t[1][i - 1] + 1;
        else
            t[1][i] = t[1][i - 1];
    }

    for(int i = 2 ; i <= m ; i++){
        for(int j = 1 ; j <= n ; j++){
            if(B[i - 1] == A[j - 1])
                t[i][j] = t[i][j - 1] + t[i - 1][j - 1];
            
            else
                t[i][j] = t[i][j - 1];
        }
    }
    return t[m][n];

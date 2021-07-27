// We fix 2 rows at first, and then apply Kadane's algorithm to find maximum sum subarray
// This result is then compared with global maximum variable to get the maximum sum submatrix at every point

// https://www.youtube.com/watch?v=kKEX4P53MyY

int maxSumSUbarray(vector<int> &A){
    int globalMax = INT_MIN , temp = 0;

    for(int i = 0 ; i < A.size() ; i++){
        temp += A[i];
        globalMax = max(temp , globalMax);

        if(temp < 0)
            temp = 0;
    }

    return globalMax;
}

int Solution::solve(vector<vector<int> > &A) {
    int n = A.size() , m = A[0].size() , res = INT_MIN;

    vector<int> temp;

    for(int i = 0 ; i < n ; i++){

        for(auto x : A[i])
            temp.push_back(x);

        res = max(res , maxSumSUbarray(temp));

        for(int j = i + 1 ; j < n ; j++){
            
            for(int k = 0 ; k < m ; k++)
                temp[k] += A[j][k];

            res = max(res , maxSumSUbarray(temp));
        }

        temp.clear();
    }

    return res;
}

// Make a vector stripSum that contains column sum of every B X 1 matrix
// The first column sum is used to calculate further column sums of the same column


int Solution::solve(vector<vector<int> > &A, int B) {
    int n = A.size();
    

    vector<vector<int>>stripSum(n , vector<int>(n , 0));

    for(int j = 0 ; j < n ; j++){
        int sum = 0;

        for(int k = 0 ; k < B ; k++){
            sum += A[k][j];
        }
        stripSum[0][j] = sum;

        for(int i = 1 ; i <= n-B ; i++){
            sum += (A[i+B-1][j] - A[i-1][j]);
            stripSum[i][j] = sum;
        }
    }

    int result = INT_MIN;
 
  // This part sums each column sum and calculates the maximum sum

    for(int i = 0 ; i <= n-B ; i++){
        int sum = 0;

        for(int j = 0 ; j < B ; j++){
            sum += stripSum[i][j];
        }
        if(sum > result)
            result = sum;
        
        for(int j = 1 ; j <= n-B ; j++){
            sum += (stripSum[i][j+B-1] - stripSum[i][j-1]);

            if(sum > result)
                result = sum;
        }
    }
    return result;



}

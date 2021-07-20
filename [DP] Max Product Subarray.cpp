// For max_temp conditions - A[i] if it is positive and max_temp is negative
// max_temp*A[i] if both the terms are positive
// min_temp*A[i] if both are large negatives

// On similar lines for min_temp

int Solution::maxProduct(const vector<int> &A) {
    int n = A.size();

    int max_temp = A[0] , min_temp = A[0];
    int globalMax = A[0];
    
    for(int i = 1 ; i < n ; i++){
        int temp = max_temp;
        
        max_temp = max(A[i] , max(max_temp*A[i] , min_temp*A[i]));
        
        globalMax = max(globalMax , max_temp);
        
        min_temp = min(A[i] , min(temp*A[i] , min_temp*A[i]));

    }

    return globalMax;

}

// Longest bitonic subsequence is longest increase subsequence + longest decreasing - 1


int Solution::longestSubsequenceLength(const vector<int> &A) {

    int N = A.size();
    if(N == 0) return 0;
    vector<int> LIS(n, 1);
    vector<int> LDS(n,1);
    
    for(int i = 1; i<n; i++){
        for(int j = 0; j<i; j++){
            //standard LIS condition
            if((A[i] > A[j]) && (LIS[i] <= LIS[j])) LIS[i] = LIS[j] + 1;
        }
    }
    
    for(int i = n-2; i>=0; i--){
        for(int j = n-1; j>i; j--){
            //standard LDS condition
            if((A[i] > A[j]) && (LDS[i] <= LDS[j])) LDS[i] = LDS[j] + 1;
        }
    }
    
   int max = LIS[0] + LDS[0] - 1; 
   for (int i = 1; i < n; i++) 
     if (LIS[i] + LDS[i] - 1 > max) 
         max = LIS[i] + LDS[i] - 1; 
   return max; 
}

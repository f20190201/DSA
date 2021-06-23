int Solution::hammingDistance(const vector<int> &A) {
    long long int res = 0;

    for(long long int i = 0 ; i < 32 ; i++){
        int ones = 0;

        for(long long int j = 0 ; j < A.size() ; j++){
            if(A[j] & (1<<i))
                ones++;
        }
        res += (ones*(A.size() - ones)*2);
    }
    
    return res%1000000007;

}

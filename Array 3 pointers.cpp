// In every iteration, increase the least number

int Solution::minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    int result = INT_MAX , a = 0 , b = 0 , c = 0;

    while(a < A.size() and b < B.size() and c < C.size()){
        int k = max(abs(A[a] - B[b]) , abs(C[c] - B[b]));
        int l = max(abs(A[a] - C[c]) , k); 
        
        result = min(result , l);


        if(A[a] <= B[b] and A[a] <= C[c])
            a++;

        else if(A[a] >= B[b] and B[b] <= C[c])
            b++;
        
        else if (C[c] <= A[a] and B[b] >= C[c])
            c++;
    }
    return result;

}

// First normally sort the array
// Then interchange elements 2 at a time

vector<int> Solution::wave(vector<int> &A) {
    sort(A.begin() , A.end());

    for(int i = 0 ; i < A.size() - 1 ; i+=2){
        int prev = A[i];
        A[i] = A[i+1];
        A[i+1] = prev;
    }
    return A;
}

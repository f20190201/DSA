int Solution::titleToNumber(string A) {
    int result = 0;
    reverse(A.begin() , A.end());

    for(int i = 0 ; i < A.size() ; i++){
        int value = A[i] - 64;
        result += (pow(26 , i)*value);
    }
    return result;
}

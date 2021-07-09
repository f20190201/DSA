int Solution::maxp3(vector<int> &A) {
    if(A.size() < 3)
        return 0;

    sort(A.begin() , A.end());

    vector<int> result;

    int prod1 = A[0] * A[1] * A[2];
    int prod2 = A[0] * A[1] * A[A.size() - 1];
    int prod3 = A[0] * A[A.size() - 2] * A[A.size() - 1];
    int prod4 = A[A.size() - 3] * A[A.size() - 2] * A[A.size() - 1];

    vector<int> v{prod1 , prod2 , prod3 , prod4};

    return *max_element(v.begin() , v.end());

}

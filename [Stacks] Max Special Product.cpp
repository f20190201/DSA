int Solution::maxSpecialProduct(vector<int> &A) {
    #define int long long int
    #define M 1000000007
    vector<int> leftMax(A.size() , -1);
    vector<int> rightMax(A.size() , A.size());

    stack<int>s;

    for(int i = 0 ; i < A.size() ; i++){
        
        while(!s.empty() and A[i] >= A[s.top()])
            s.pop();
        
        if(!s.empty())
            leftMax[i] = s.top();

        s.push(i);
    }

    stack<int>s1;

    for(int i = A.size() - 1 ; i >= 0 ; i--){
        
        while(!s1.empty() and A[i] >= A[s1.top()])
            s1.pop();
        
        if(!s1.empty())
            rightMax[i] = s1.top();

        s1.push(i);
    }

    int result = LLONG_MIN;

    for(int i = 0 ; i < A.size() ; i++){
        
        if(leftMax[i] >= 0 and rightMax[i] < A.size()){
            int prod =  (((leftMax[i]) * (rightMax[i])));
            result = max(result , prod);
        }

    }
    return (result%M < 0) ? 0 : (result%M);

}

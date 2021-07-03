vector<int> Solution::prevSmaller(vector<int> &A) {
    vector<int> v(A.size() , -1);
    stack<int>s;

    for(int i = 0 ; i < A.size() ; i++){
        
        while(!s.empty() and s.top() >= A[i])
            s.pop();

        if(!s.empty())
            v[i] = s.top();

        s.push(A[i]);

    }

    return v;


}

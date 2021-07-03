int Solution::largestRectangleArea(vector<int> &A) {
    int n = A.size();
    stack<int>s;                                //The top of this stack stores the left nearest smaller number. In case it doesn't, we pop it till it does. 
    vector<int>leftMin(n , -1);                 //Vector to store Left Nearest smaller number
    vector<int>rightMin(n , n);                 //Vector to store Right Nearest smaller number

    for(int i = 0 ; i < n ; i++){
        while(!s.empty() and A[s.top()] >= A[i])
            s.pop();

        if(!s.empty())
            leftMin[i] = s.top();

        s.push(i);
    }

    while(!s.empty())
        s.pop();

    for(int i = n - 1 ; i >= 0 ; i--){
        while(!s.empty() and A[s.top()] >= A[i])
            s.pop();

        if(!s.empty())
            rightMin[i] = s.top();

        s.push(i);
    }
    
    int result = INT_MIN;

    for(int i = 0 ; i < n ; i++){
        int area = (rightMin[i] - leftMin[i] - 1)* A[i];
        result = max(result , area);
    }
    return result;

}

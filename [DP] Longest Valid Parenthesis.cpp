int Solution::longestValidParentheses(string A) {
    stack<int>s;
    int globalMax = 0;

    s.push(-1);

    for(int i = 0 ; i < A.size() ; i++){
        
        if(A[i] == '(')
            s.push(i);
        
        else{
            s.pop();
            
            if(s.empty())
                s.push(i);
            
            else
                globalMax = max(globalMax , i - s.top());

        }

    }

    return globalMax;
}


------------------------------------------------------------------------------------------------
  
  

// Each pair of braces should house at least one sign
// If element is a sign or '(' , push it to the stack
// If element is a ')'  , pop element until s.top == '(' and finally pop this as well. The idea is, we are removing the contents between the two latest ()
// If s.top == '(' and element is ')' , redundant braces are present since there isn't any sign between the pairs of braces

int Solution::braces(string A) {
    stack<int>s;

    for(int i = 0 ; i < A.size() ; i++){
        if((A[i] == '+') or (A[i] == '/') or (A[i] == '*') or (A[i] == '-') or (A[i] == '('))
            s.push(A[i]);
        
        if(A[i] == ')'){
            if(s.top() == '(')
                return 1;
            else{
                while(s.top() != '(')
                    s.pop();
                s.pop();
            }
                
        }

    }

    return 0;

}

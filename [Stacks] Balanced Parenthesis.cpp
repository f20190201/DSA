// Keep pushing '('
// If we encounter a ')' we pop an element from the stack. If before popping the stack was empty, return 0
// Finally after iterating over the string, if stack is empty, return 1, else return 0

int Solution::solve(string A) {
    stack<char>s;

    for(int i = 0 ; i < A.size() ; i++){
        if(A[i] == '(')
            s.push(A[i]);

        else if(A[i] == ')'){
            
            if(s.empty())
                return 0;
            
            s.pop();

        }

    }

    if(!s.empty())
        return 0;
    return 1;

}

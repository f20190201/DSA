// The idea is to maintain a stack which contains all the operators and opening and closing brackets. If the current character is ")" and st.top() is "(" 
// then we have a redundant bracket condition.

bool RedundantBracket(string s , int n){
    bool flag = false;
    stack<char> st;
    
    for(int i = 0 ; i < n ; i++){
        if(s[i] == '+' || s[i] == '-' || s[i] == '/' || s[i] == '*' || s[i] == '(')
            st.push(s[i]);
            
        if(s[i] == ')'){
            if(st.top() == '(')
                flag = true;
            while(st.top() == '+' || st.top() == '-' || st.top() == '/' || st.top() == '*')
                st.pop();
            st.pop();
        }
    }
    
    
 return flag;   
} 

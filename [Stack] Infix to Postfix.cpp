
// A precedence function which gives us the precedence of an operator. If it is not an operator, it returns -1

int precedence(char c){
        if(c == '-' || c == '+')
            return 1;
            
        if(c == '*' || c == '/')
            return 2;
            
        if(c == '^')
            return 3;
    
        else 
            return -1;
    }
    
 
    string infixToPostfix(string s)
    {
       
        stack<char> st;
        
        string final;
        
        for(int i = 0; i<s.length(); i++){
        
        if((s[i] >='a' && s[i]<='z') || (s[i] >= 'A' && s[i] <= 'Z'))
            final+=s[i];
            
        else if(s[i] == '(')
            st.push('(');
            
        else if(s[i] == ')'){
            while(!st.empty() && (st.top() != '(')){
                final+=st.top();
                st.pop();
            }
          if(!st.empty())
            st.pop();  
            
        }
       
        
            
        else{
        
        while(!st.empty() && (precedence(st.top()) >= precedence(s[i]) )){
            final += st.top();
            st.pop();
        }
        st.push(s[i]); 
        }
        }
        
        while(!st.empty()){
            final += st.top();
            st.pop();
        }
        
        return final;
    }

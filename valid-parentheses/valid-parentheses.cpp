class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for(int i = 0 ; i < s.size() ; i++){
            
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
                st.push(s[i]);
            
            if(st.empty())
                return 0;
            
            else if(s[i] == ')'){
                
                char top = st.top();
                
                st.pop();
                
                if(top != '(')
                    return 0;
            }
            
            else if(s[i] == '}'){
                
                char top = st.top();
                
                st.pop();
                
                if(top != '{')
                    return 0;
            }
            
            else if(s[i] == ']'){
                
                char top = st.top();
                
                st.pop();
                
                if(top != '[')
                    return 0;
            }
            
        }
        
        return st.empty();
    }
};
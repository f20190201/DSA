class Solution {
public:
    bool isValid(string A){
        stack<char>s;
        
        for(auto c : A){
            
            if(c == '(')
                s.push('(');
            
            else{
                if(s.empty())
                    return 0;
                else
                    s.pop();
            }
        }
        return (s.empty());
        
    }
    vector<string> result; 
    
    void solve(int A , int index , string s){
        
        if(index == A){
            if(isValid(s))
                result.push_back(s);
            return;
        }
        
        s.push_back('(');
        solve(A , index + 1 , s);
        s.pop_back();
        s.push_back(')');
        solve(A , index + 1 , s);
        
        return;
    }
    
    vector<string> generateParenthesis(int n) {   
        result.clear();
        string s = "";
        
        solve(2 * n , 0 , s);
        
        return result;
    }
};
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


----------------------------------------------------------------------------------------------------------------
   // Idea is to keep track of number of close and open brackets in a stream
   // At each moment, the number of open brackets should be <= n and number of closed brackets <= open
    
    vector<string> result; 
    
    void solve(int n , int close , int open , string s){
        if(s.length() == 2 * n){
            result.push_back(s);
            return;
        }
        
        if(open < n){
            solve(n , close , open + 1 , s + '(');
        }
        
        
        if(close < open){
            solve(n , close + 1 , open , s + ')');
        }
        
        return;
    }
    
    vector<string> generateParenthesis(int n) {   
        result.clear();
        string s = "";
        
        solve(n , 0 , 0 , s);
        
        return result;
    }
};

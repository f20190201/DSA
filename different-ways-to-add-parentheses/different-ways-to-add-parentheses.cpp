class Solution {
public:
    
    vector<int> solve(string s){
        vector<int> res;
        
        for(int i = 0 ; i < s.size() ; i++){
            auto ch = s[i];
            
            if(ch == '-' || ch == '+' || ch == '*'){
                auto left = solve(s.substr(0 , i)) , right = solve(s.substr(i + 1));
                
                for(auto val1 : left){
                    
                    for(auto val2 : right){
                        
                        if(ch == '-')
                            res.push_back(val1 - val2);
                        
                        else if(ch == '+')
                            res.push_back(val1 + val2);
                        
                        else
                            res.push_back(val1 * val2);
                    }
                }
            }
        }
        
        if(res.size() == 0)
            res.push_back(stoi(s));
        
        return res;
    }
    
    vector<int> diffWaysToCompute(string s) {
         
        
        return solve(s);
    }
};
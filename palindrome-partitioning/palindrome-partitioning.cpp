class Solution {
public:
    vector<vector<string>> result;
    
    bool isPalin(string s){
        int start = 0 , end = s.size() - 1;
        
        while(start < end){
            if(s[start] != s[end])
                return 0;
            
            start++;
            end--;
        }
        
        return 1;
    }
    
    void solve(string s , vector<string> &v , int start){
        
        if(start == s.size()){
            result.push_back(v);
            return;
        }
        
        for(int i = start ; i < s.size() ; i++){
            
            string str = s.substr(start , i - start + 1);
            
            if(isPalin(str)){
                v.push_back(str);
            
                solve(s , v , i + 1);
            
                v.pop_back();
            }
        }
        
        return;
        
    }
    
    vector<vector<string>> partition(string s) {
        result.clear();
        
        vector<string> v;
        
        solve(s , v , 0);
        
        return result;
    }
};
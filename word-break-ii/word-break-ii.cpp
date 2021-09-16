class Solution {
public:
    vector<vector<string>>res;
    
    void solve(string s, vector<string>& dict , vector<string> &v){
        
        if(s.size() == 0){
            res.push_back(v);
            return;
        }
        
        for(auto word: dict){
            
            if(s.compare(0 , word.size() , word) == 0){
                v.push_back(word);
                
                solve(s.substr(word.size()) , dict , v);
                
                v.pop_back();
            }   
        }
        
        return;
    }
    
    string arrToStr(vector<string>&v){
        string s = "";
        
        for(auto word : v){
            s += word;
            s.push_back(' ');
        }
        s.pop_back();
        
        return s;
    }
    
    vector<string> wordBreak(string s, vector<string>& dict) {
        //try making every word a prefix   
        res.clear();
        
        vector<string>v;
        
        solve(s , dict , v);
        
        vector<string> ans;
        
        for(auto v : res){
            ans.push_back(arrToStr(v));
        }
        
        
        return ans;
    }
};
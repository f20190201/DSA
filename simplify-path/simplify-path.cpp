class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        string word;
        stack<string> s;
        s.push("/");
        
        while(getline(ss , word , '/')){
            
            if(word.size() == 0 || word == ".")
                continue;
            
            if(word == ".."){
                if(s.top() != "/")
                    s.pop();
            }
            
            else
                s.push(word);
            
        }
        
        string res = "";
        
        while(!s.empty()){
            res = "/" + s.top() + res;
            s.pop();
        }
        
        if(res.size() <= 2)
            return "/";
        
        return res.substr(2);
            
    }
};
class Solution {
public:
    string removeDuplicates(string s) {
        int i = 0  , j = 0;
        
        for( ; j < s.size() ; i++ , j++){
            s[i] = s[j];
            
            if(i > 0 && s[i - 1] == s[i])
                i -= 2;
            
        }
        
        return s.substr(0 , i);
    }
};
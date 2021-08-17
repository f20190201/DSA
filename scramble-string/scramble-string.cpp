class Solution {
public:
    unordered_map<string , bool>mp;
    
    bool solve(string s1 , string s2){
        
        if(s1 == s2)
            return 1;
        
        int n = s1.size();
        
        if(n <= 1)
            return 0;
        
        if(mp.count(s1 + ' ' + s2))
            return mp[s1 + ' ' + s2];
        
        bool flag = 0;
        
        for(int i = 1 ; i < n ; i++){
            string s11 = s1.substr(0 , i);
            string s12 = s1.substr(i , n - i);
            // string s13 = s1.substr(n - i , i);
            
            string s21 = s2.substr(0 , i);
            string s22 = s2.substr(i , n - i);
            string s23 = s2.substr(n - i , i);
            string s24 = s2.substr(0 , n - i);
            
            if((solve(s11 , s21) && solve(s12 , s22)) || (solve(s11 , s23) && solve(s12 , s24))){
                flag = 1;
                break;
            }
        }
        
        return mp[s1 + ' ' + s2] = flag;
    }
    
    bool isScramble(string s1, string s2) {
        mp.clear();
        int n1 = s1.size() , n2 = s2.size();
        
        if(n1 != n2)
            return 0;
        
        if(n1 == 0 && n2 == 0)
            return 1;
        
        return solve(s1 , s2);
    }
};
class Solution {
public:
    unordered_map<string , int>mp , dp;
    
    
    bool solve(string s){
        int n = s.size();
        
        if(n == 0)
            return 1;
        
        if(dp.count(s))
            return dp[s];
        
        if(mp.count(s))
            return dp[s] = 1;
        
        for(int k = 0 ; k < s.size() - 1 ; k++){
            string s1 = s.substr(0 , k + 1) , s2 = s.substr(k + 1 , n - k - 1);
            
            bool left = solve(s1);
            bool right = solve(s2);
            
            if(left && right)
                return dp[s] = 1;
        }
        
        return dp[s] = 0;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        mp.clear();
        dp.clear();
        
        for(auto word : wordDict)
            mp[word]++;
        
        return solve(s);
    }
};
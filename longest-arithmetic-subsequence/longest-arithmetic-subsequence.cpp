class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size() , ans = 2;
        
        if(n <= 2)
            return n;
        
        vector<unordered_map<int , int>>mp(n);
        
        vector<int>dp(n , 1);
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < i ; j++){
                
                int diff = nums[i] - nums[j];
                
                if(mp[j].count(diff)){
                    
                    dp[i] = max(dp[i] , 1 + mp[j][diff]);
                    
                    mp[i][diff] = 1 + mp[j][diff];
                    
                }
                
                else
                    mp[i][diff] = 2;
            }
        }
        
        for(auto x : dp)
            ans = max(ans , x);
        
        return ans;
    }
};
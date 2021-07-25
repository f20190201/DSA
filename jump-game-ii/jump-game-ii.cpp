class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int dp[n];
        for(int i = 0 ; i < n ; i++)
            dp[i] = INT_MAX;
        
        dp[0] = 0;
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j <= nums[i] ; j++){
                
                if(i + j >= n)
                    continue;
                
                if(dp[i + j] >= dp[i] + 1)
                    dp[i + j] = dp[i] + 1;
            }
        }
        
        return dp[n - 1];
    }
};
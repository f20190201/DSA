class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size() , sum = 0;
        
        for(auto x : nums)
            sum += x;
        
        if(sum % 2 != 0)
            return 0;
        
        sum = sum / 2;
        
        int dp[n + 1][sum + 1];
        
        for(int i = 0 ; i <= n ; i++)
            dp[i][0] = 1;
        
        for(int j = 1 ; j <= sum ; j++)
            dp[0][j] = 0;
        
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= sum ; j++){
                
                if(nums[i - 1] <= j)
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
                
                else
                    dp[i][j] = dp[i - 1][j];    
                
            }
        }
        
        return dp[n][sum];
    }
};
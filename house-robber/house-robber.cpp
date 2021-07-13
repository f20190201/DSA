class Solution {
public:
    int bounty(vector<int>A , int n){
        
        if(!n)
            return 0;
        
        if(n == 1)
            return A[0];
        
        return max(bounty(A , n - 1) , A[n - 1] + bounty(A , n - 2));
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 1)
            return nums[0];
        
        if(n == 2)
            return max(nums[0] , nums[1]);
        
        int dp[n + 1];
        
        memset(dp , 0 , sizeof(dp));
        
        dp[1] = nums[0];
        dp[2] = max(nums[0] , nums[1]);       
        
        for(int i = 2 ; i <= nums.size() ; i++)
            dp[i] = max(dp[i - 1] , nums[i - 1] + dp[i - 2]);
        
        return dp[n];
    }
};
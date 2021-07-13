class Solution {
public:
    int bounty(vector<int>& A){
        int n = A.size();
        
        int dp[n + 1];
        memset(dp , 0 , sizeof(dp));
        
        dp[1] = A[0];
        dp[2] = max(A[0] , A[1]);
        
        for(int i = 2 ; i <= n ; i++)
            dp[i] = max(dp[i - 1] , A[i - 1] + dp[i - 2]);
        
        return dp[n];
        
    }
    
    
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 1)
            return nums[0];
        if(n == 2)
            return max(nums[0] , nums[1]);
        
        vector<int>v1 , v2;
        
        v1.assign(nums.begin() , nums.end() - 1);
        v2.assign(nums.begin() + 1 , nums.end());
        
        return max(bounty(v1) , bounty(v2));
        
    }
};
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 1)
            return 1;
        
        int dp[n + 1];
        memset(dp , 0 , sizeof(dp));
        
        dp[0] = 1;
        
        for(int i = 0 ; i < n ; i++){
            
            if(dp[i] == 0)
                return 0;
                
            int jump = nums[i];
            
            
            while(jump >= 0){
                
                if(i + jump >= n)
                    return 1;
                
                else
                    dp[i + jump] = 1;
                
                jump--;
            }
        }
        return dp[n-1];
    }
};
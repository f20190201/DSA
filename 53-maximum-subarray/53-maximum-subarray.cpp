class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size() , maxSum = INT_MIN;
        int dp[n];
        dp[0] = nums[0];
        maxSum = max(maxSum , dp[0]);
        
        for(int i = 1 ; i < n ; i++){
            dp[i] = nums[i] + (dp[i - 1] > 0 ? dp[i - 1] : 0);
            
            maxSum = max(maxSum , dp[i]);
        }
        
//         int maxSum = INT_MIN , tempMax = 0;
        
//         for(int i = 0 ; i < nums.size() ; i++){
//             tempMax += nums[i];
            
//             maxSum = max(tempMax , maxSum);
            
//             if(tempMax < 0)
//                 tempMax = 0;
//         }
        
        return maxSum;
    }
};
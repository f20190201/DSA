class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = INT_MIN , temp = 0;
        
        for(int i = 0 ; i < nums.size() ; i++){
            temp += nums[i];
            
            if(temp > result)
                result = temp;
            
            if(temp < 0)
                temp = 0;
        }
        return result;
    }
};


---------------------------------------------------------------------------------------------------

public int maxSubArray(int[] A) {
        int n = A.length;
        int[] dp = new int[n];//dp[i] means the maximum subarray ending with A[i];
        dp[0] = A[0];
        int max = dp[0];
        
        for(int i = 1; i < n; i++){
            dp[i] = A[i] + (dp[i - 1] > 0 ? dp[i - 1] : 0);
            max = Math.max(max, dp[i]);
        }
        
        return max;
}

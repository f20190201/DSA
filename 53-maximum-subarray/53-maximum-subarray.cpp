class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN , tempMax = 0;
        
        for(int i = 0 ; i < nums.size() ; i++){
            tempMax += nums[i];
            
            maxSum = max(tempMax , maxSum);
            
            if(tempMax < 0)
                tempMax = 0;
        }
        
        return maxSum;
    }
};
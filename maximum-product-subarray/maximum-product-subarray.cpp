class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int globalMax = nums[0] , temp_max = nums[0] , temp_min = nums[0];
        
        for(int i = 1 ; i < nums.size() ; i++){
            int temp = temp_max;
            
            temp_max = max(nums[i] , max(nums[i] * temp_max , nums[i] * temp_min));
            
            globalMax = max(globalMax , temp_max);
            
            temp_min = min(nums[i] , min(temp * nums[i] , temp_min * nums[i]));
        }
        
        return globalMax;
    }
};
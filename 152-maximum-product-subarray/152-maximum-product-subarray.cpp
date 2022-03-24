class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int globalMax = nums[0] , tempMax = nums[0] , tempMin = nums[0];
        
        for(int i = 1 ; i < nums.size() ; i++){
            
            int temp = tempMax;
            
            tempMax = max({nums[i] , tempMax*nums[i] , tempMin*nums[i]});
            
            globalMax = max(globalMax , tempMax);
            
            tempMin = min({nums[i] , temp*nums[i] , tempMin*nums[i]});
        }
        
        return globalMax;
    }
};
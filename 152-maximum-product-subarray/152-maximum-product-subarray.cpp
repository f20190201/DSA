class Solution {
public:
    int maxProduct(vector<int>& nums) {
//         int globalMax = nums[0] , tempMax = nums[0] , tempMin = nums[0];
        
//         for(int i = 1 ; i < nums.size() ; i++){
            
//             int temp = tempMax;
            
//             tempMax = max({nums[i] , tempMax*nums[i] , tempMin*nums[i]});
            
//             globalMax = max(globalMax , tempMax);
            
//             tempMin = min({nums[i] , temp*nums[i] , tempMin*nums[i]});
//         }
        
        int left = 0 , right = 0 , globalMax = nums[0];
        
        for(int i = 0 ; i < nums.size() ; i++){
            left = (left != 0 ? left : 1)*nums[i];
            right = (right != 0 ? right : 1)*nums[nums.size() - 1 - i];
            
            globalMax = max({globalMax , left , right});
        }
        
        
        
        return globalMax;
    }
};
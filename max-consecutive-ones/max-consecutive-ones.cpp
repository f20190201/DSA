class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0 , globalMax = 0;
        
        for(int i = 0 ; i < nums.size() ; i++){
            
            while(i < nums.size() && nums[i] == 1){
                count++;
                i++;
            }
            
            globalMax = max(globalMax , count);
            count = 0;
        }
        
        return globalMax;
    }
};
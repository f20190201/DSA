class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red = 0 , blue = nums.size() - 1;
        
        if(nums.size() == 1)
            return;
        
        for(int i = 0 ; i <= blue ; i++){
            
            if(nums[i] == 0){
                swap(nums[red] , nums[i]);
                red++;
            }
            
            else if(nums[i] == 2){
                
                swap(nums[i] , nums[blue]);
                blue--;
                i--;
            }
        }
        
        return;
    }
};
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        
        int unique = 0 , i = 0;  
        
        for(; i < nums.size() - 1 ; i++){
            
            if(nums[i] != nums[i + 1]){
                nums[unique] = nums[i];
                unique++;    
            }
        }
        
        nums[unique] = nums[i];
        
        return unique + 1;
    }
};


-----------------------------------------------------------------------------------------------
    
    
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        
        int unique = 0;
        
        for(int i = 1 ; i < nums.size(); i++){
            
            if(nums[unique] != nums[i]){
                unique++;
                nums[unique] = nums[i];
            }
            
        }
        
        return unique + 1;
    }

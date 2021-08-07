class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int num = nums[0] , freq = 0;
        
        for(auto x : nums){
            if(x == num)
                freq++;
            
            else{
                
                if(freq == 0){
                    freq = 1;
                    num = x;
                }
                
                else
                    freq--;
            }
        }
        
        int count = 0;
        
        for(auto x: nums)
            if(x == num)
                count++;
        
        return num;
    }
};
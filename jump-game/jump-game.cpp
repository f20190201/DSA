class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size() , start = n - 1;
        
        for(int i = n - 2 ; i >= 0 ; i--){
            if(nums[i] + i >= start)
                start = i;
        }
        
        return (start <= 0);
    }
};
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // n^2
//         int n = nums.size();
        
//         for(int i = 0 ; i < n ; i++){
//             for(int j = i + 1 ; j < n ; j++)
//                 if(nums[i] == nums[j])
//                     return nums[i];
//         }
        
        int slow = nums[0] , fast = nums[nums[0]];
        
        while(fast != slow){
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        
        fast = 0;
        
        while(fast != slow){
            slow = nums[slow];
            fast = nums[fast];
        }
        
        return slow;
        
        return -1;
    }
};
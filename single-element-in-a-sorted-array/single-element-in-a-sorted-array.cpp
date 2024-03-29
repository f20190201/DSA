// https://www.youtube.com/watch?v=PzszoiY5XMQ&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=64

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0 , high = nums.size() - 2;
        
        while(low <= high){
            int mid = low + (high - low) / 2;
            
            if(mid % 2){
                if(nums[mid] == nums[mid - 1])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
            
            else{
                if(nums[mid] == nums[mid + 1])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }
        
        return nums[low];
    }
};

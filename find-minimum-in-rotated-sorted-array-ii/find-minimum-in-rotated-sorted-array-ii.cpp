class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0 , high = n - 1;
        
        while(low <= high){
            int mid = low + (high - low) / 2;
    
            if(nums[mid] > nums[high])
                low = mid + 1;
            
            else if(nums[low] > nums[mid]){
                high = mid;
                low++;
            }
            
            else
                high--;
    
        }
        
        return nums[low];
    }
};
class Solution {
public:
    int pivot(vector<int>& nums){
        int l = 0 , r = nums.size() - 1;
        
        while(l <= r){
            int mid = (l + r) / 2;
            
            if(nums[l] <= nums[r]){
                return l;
            }
            
            if(nums[mid] > nums[mid + 1])
                return mid + 1;
            
            if(nums[mid] < nums[mid - 1] && nums[mid] < nums[mid + 1])
                return mid;
            
            else if(nums[l] < nums[mid])
                l = mid + 1;
            
            else 
                r = mid - 1;
        }
        
        return -1;
        
    }
    
    int BS(vector<int>& A , int start , int end , int target){
        int l = start , r = end;
        
        while(l <= r){
            int mid = (l + r) / 2;
            
            if(A[mid] == target)
                return mid;
            
            if(A[mid] < target)
                l = mid + 1;
            
            else
                r = mid - 1;        
        }
        
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        int p = pivot(nums);
        // cout<<p;
        
        int l = BS(nums , 0 , p - 1 , target);
            if(l != -1)
                return l;
        int r = BS(nums , p , nums.size() - 1 , target);
            if(r != -1)
                return (r);
        
        return -1;
        
    }
};
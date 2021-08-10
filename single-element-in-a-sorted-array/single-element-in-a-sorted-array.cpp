class Solution {
public:
    int firstOcc(vector<int>& A , int target){
        int low = 0 , high = A.size() - 1 , res = -1;
        
        while(low <= high){
            int mid = low + (high - low) / 2;
            
            if(A[mid] > target)
                high = mid - 1;
            
            else if(A[mid] < target)
                low = mid + 1;
            
            else{
                res = mid;
                high = mid - 1;
            }
        }
        
        return res;
    }
    
    int lastOcc(vector<int>& A , int target){
        int low = 0 , high = A.size() - 1 , res = A.size();
        
        while(low <= high){
            int mid = low + (high - low) / 2;
            
            if(A[mid] > target)
                high = mid - 1;
            
            else if(A[mid] < target)
                low = mid + 1;
            
            else{
                res = mid;
                low = mid + 1;
            }
        }
        
        return res;
    }
    
    int singleNonDuplicate(vector<int>& nums) {
        
        for(int i = 0 ; i < nums.size() ; i++){
            
            if(firstOcc(nums , nums[i]) == lastOcc(nums , nums[i]))
                return nums[i];
        }
        
        return -1;
    }
};
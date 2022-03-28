class Solution {
public:
    int pivot(vector<int>&A){
        int n = A.size() , l = 0 , r = n - 1;
        
        while(l < r){
            
            if(A[l] < A[r])
                return l;
            
            int mid = l + (r - l)/2;
            
            if(A[l] <= A[mid])
                l = mid + 1;
            
            else
                r = mid;
            
        }
        
        return l;
    }
    
    int BS(vector<int>&nums , int l , int r ,  int target){
        
        while(l <= r){
            int mid = l + (r - l)/2;
            
            if(nums[mid] == target)
                return mid;
            
            else if(target > nums[mid])
                l = mid + 1;
            else
                r = mid - 1;
        }
        
        return -1;
    }
    
    int search(vector<int>& nums, int target) {  
        int p = pivot(nums);
        
        int s1 = BS(nums , 0 , p - 1 , target) , s2 = BS(nums , p , nums.size() - 1 , target);
        if(s1 != -1)
            return s1;
        return s2;
    }
};
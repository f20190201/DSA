class Solution {
public:
    int first(vector<int>& A , int target){
        int l = 0 , r = A.size() - 1 , res = -1;
        
        while(l <= r){
            int mid = (l + r) / 2;
            
            if(A[mid] == target){
                res = mid;
                r = mid - 1;
            }
            
            else if(A[mid] > target)
                r = mid - 1;
            
            else
                l = mid + 1;
                
        }
        return res;
        
    }
    
    int last(vector<int>& A , int target){
        int l = 0 , r = A.size() - 1 , res = -1;
        
        while(l <= r){
            int mid = (l + r) / 2;
            
            if(A[mid] == target){
                res = mid;
                l = mid + 1;
            }
            
            else if(A[mid] > target)
                r = mid - 1;
            
            else
                l = mid + 1;
                
        }
        return res;
        
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        return {first(nums , target) , last(nums , target)};
    }
};
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size() - 1;
        int i = n;
        
        for(; i >= 0 ; i--){
            
            if(i == 0){
                sort(nums.begin() , nums.end());
                return;
            }
            
            if(nums[i] > nums[i - 1])
                break;
        }
        i--;
        int toSwap = i + 1;
        
        for(int j = i + 1 ; j <= n ; j++){
            if(nums[j] > nums[i])
                toSwap = ((nums[toSwap] > nums[j]) ? j : toSwap);
        }
        swap(nums[i] , nums[toSwap]);
        
        sort(nums.begin() + i + 1 , nums.end());
        
        return;
    }
};
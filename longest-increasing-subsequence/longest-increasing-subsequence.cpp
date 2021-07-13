class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        
        int t[n + 1];
        t[0] = INT_MIN;
        
        for(int i = 1 ; i <= n ; i++)
            t[i] = INT_MAX;
        
        for(int i = 0 ; i < n ; i++){
            
            int index = upper_bound(t , t + n + 1 , nums[i]) - t;
            
            if(t[index - 1] < nums[i] and t[index] > nums[i])
                t[index] = nums[i];
        }
        
        for(int i = n ; i >= 0 ; i--)
            if(t[i] != INT_MAX)
                return i;
        
        return 0;
        
    }
};
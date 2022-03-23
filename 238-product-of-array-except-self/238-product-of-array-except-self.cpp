class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n , 0) , suffix(n , 0);
        prefix[0] = nums[0];
        
        for(int i = 1 ; i < n ; i++)
            prefix[i] = prefix[i - 1]*nums[i];
        
        suffix[n - 1] = nums.back();
        
        for(int i = n - 2 ; i >= 0 ; i--)
            suffix[i] = suffix[i + 1]*nums[i];
        
        vector<int> result(n , 0);
        
        for(int i = 1 ; i < n - 1 ; i++)
            result[i] = prefix[i - 1]*suffix[i + 1];
        
        result[0] = suffix[1];
        result[n - 1] = prefix[n - 2];
        
        return result;
    }
};
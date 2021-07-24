class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> result;
        if(n < 3)
            return {};
        sort(nums.begin() , nums.end());
        
        for(int i = 0 ; i < n ; i++){
            int target = -nums[i];
            
            int l = i + 1 , r = n - 1;
            
                while(l < r){
                    int sum = nums[l] + nums[r];
                    
                    if(sum > target)
                        r--;
                    
                    else if(sum < target)
                        l++;
                    
                    else{
                        vector<int> v(3);
                        v[0] = nums[i];
                        v[1] = nums[l];
                        v[2] = nums[r];
                        result.push_back(v);
                        
                        while(l < r and nums[l] == v[1])
                            l++;
                        
                        while(l < r and nums[r] == v[2])
                            r--;
                    }
                }
                while(i < n - 1 and nums[i] == nums[i + 1])
                    i++;
                
        }
        return result;
    }
};
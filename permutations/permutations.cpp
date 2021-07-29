class Solution {
public:
    vector<vector<int>> result;
    
    void solve(vector<int>& nums , vector<int> &v , int start , int end){
        
        if(start == end){
            result.push_back(nums);
            return;
        }
        
        for(int i = start ; i <= end ; i++){
            
            
            swap(nums[start] , nums[i]);
            
            solve(nums , v , start + 1 , end);
            
            swap(nums[start] , nums[i]);
            
            
            
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        result.clear();
        
        vector<int> v;
        
        solve(nums , v , 0 , nums.size() - 1);
        
        return result;
    }
};
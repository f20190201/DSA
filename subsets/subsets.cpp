class Solution {
public:
    vector<vector<int>> result;
    
    void solve(vector<int> &nums , vector<int> &v , int index){
        
        if(index == nums.size()){
            result.push_back(v);
            return;
        }
        
        v.push_back(nums[index]);
        
        solve(nums , v , index + 1);
        
        v.pop_back();
        
        solve(nums , v , index + 1);
        
        return;
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        result.clear();
        vector<int>v;
        
        solve(nums , v , 0);
        
        return result;
    }
};
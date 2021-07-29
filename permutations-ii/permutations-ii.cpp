class Solution {
public:
    set<vector<int>>s;
    
    void solve(vector<int>& nums , int start , int end){
        if(start == end){
            s.insert(nums);
            return;
        }
        
        for(int i = start ; i <= end ; i++){
            swap(nums[start] , nums[i]);
            
            solve(nums , start + 1 , end);
            
            swap(nums[start] , nums[i]);
        }
        
        return;
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        s.clear();
        
        vector<vector<int>> result;
        
        solve(nums , 0 , nums.size() - 1);
        
        for(auto it = s.begin() ; it != s.end() ; ++it)
            result.push_back(*it);
        
        return result;
    }
};
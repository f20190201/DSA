class Solution {
public:
    vector<vector<int>> result;
    
    void solve(vector<int>&A , vector<int> &v , int sum , int target , int index , int n){
        if(index == n){
            if(sum == target)
                result.push_back(v);
            return;
        }
        
        if(sum > target)
            return;
        
        sum = sum + A[index];
        v.push_back(A[index]);
        solve(A , v , sum , target , index , n);
        v.pop_back();
        sum = sum - A[index];
        solve(A , v , sum , target , index + 1 , n);
        
        return;
        
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        result.clear();
        
        vector<int> v;
        
        solve(candidates , v , 0 , target , 0 , candidates.size());
        
        return result;
    }
};
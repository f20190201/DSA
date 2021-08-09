class Solution {
public:
    vector<vector<int>> result;
    
    int t;
    
    void solve(vector<int>&A , vector<int> &v , int sum , int index , int n){
        if(index == n){
            if(sum == t)
                result.push_back(v);
            return;
        }
        
        if(sum > t)
            return;
        
        
        v.push_back(A[index]);
        
        solve(A , v , sum + A[index] , index , n);
        
        v.pop_back();

        solve(A , v , sum , index + 1 , n);
        
        return;
        
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        result.clear();
        t = target;
        vector<int> v;
        
        solve(candidates , v , 0 , 0 , candidates.size());
        
        return result;
    }
};
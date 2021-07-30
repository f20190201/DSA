class Solution {
public:
    vector<vector<int>> result;
    
    void solve(vector<int>&v , int n , int k , int num){
        
        if(num > n){
            if(v.size() == k)
                result.push_back(v);
            return;
        }
        
        v.push_back(num);
        
        solve(v , n , k , num + 1);
        
        v.pop_back();
        
        solve(v , n , k , num + 1);
        
        return;
        
    }
    
    vector<vector<int>> combine(int n, int k) {
        result.clear();
        vector<int>v;
        
        solve(v , n , k , 1);
        
        return result;
    }
};
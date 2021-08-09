class Solution {
public:
    set<vector<int>>s;
    
    void solve(vector<int>& A , vector<int> v , int index){
        if(index == A.size()){
            sort(v.begin() , v.end());
            s.insert(v);
            return;
        }
        
        v.push_back(A[index]);
        
        solve(A , v , index + 1);
        
        v.pop_back();
        
        solve(A , v , index + 1);
        
        return;
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        s.clear();
        
        vector<vector<int>> result;
        vector<int> v;
        
        solve(nums , v , 0);
        
        for(auto it = s.begin() ; it != s.end() ; ++it){
            result.push_back(*it);
        }
        
        return result;
    }
};
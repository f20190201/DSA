class Solution {
public:
    vector<vector<int>> result;
    
    void solve(vector<int>& A , int index){
        
        if(index == A.size()){
            result.push_back(A);
            return;
        }
        
        for(int i = index ; i < A.size() ; i++){
            
            swap(A[i] , A[index]);
            
            solve(A , index + 1);
            
            swap(A[i] , A[index]);
            
        }
        
        return;
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        result.clear();
        
        solve(nums , 0);
        
        return result;
    }
};
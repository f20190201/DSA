class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& A) {
        vector<vector<int>> result;
        
        sort(A.begin() , A.end()); 
        
        int start = A[0][0];
        int end = A[0][1];
        bool flag = 1;
        
        for(int i = 1 ; i < A.size() ; i++){
            
            while((i < A.size()) && end >= A[i][0]){
                end = max(end , A[i][1]);
                i++;
            }
            
            if(i == A.size())
                break;
            
            result.push_back({start , end});
            
            start = A[i][0];
            end = A[i][1];
        }
        result.push_back({start , end});
        
        return result;
    }
};
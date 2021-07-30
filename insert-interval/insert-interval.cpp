class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& A, vector<int>& add) {
        A.push_back(add);
        sort(A.begin() , A.end());
        vector<vector<int>> result;
        
        int start = A[0][0] , end = A[0][1];
        
        for(int i = 1 ; i < A.size() ; i++){
            
            while(i < A.size() && A[i][0] <= end){
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


--------------------------------------------------------------------------------------------------------------------------------------------


class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& A, vector<int>& add) {
        // A.push_back(add);
        // sort(A.begin() , A.end());
        
        int i = 0;
        
        while(i < A.size() && A[i][0] < add[0])
            i++;
        
        A.insert(A.begin() + i , add);
        
        
        vector<vector<int>> result;
        
        int start = A[0][0] , end = A[0][1];
        
        for(int i = 1 ; i < A.size() ; i++){
            
            while(i < A.size() && A[i][0] <= end){
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

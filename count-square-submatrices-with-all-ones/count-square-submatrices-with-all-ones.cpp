class Solution {
public:
    int countSquares(vector<vector<int>>& A) {
        
        int m = A.size() , n = A[0].size() , result = 0;
        
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                
                if(A[i][j]){
                    
                    if(!i or !j)
                        result++;
                    
                    else{
                        vector<int> v {A[i - 1][j] , A[i - 1][j - 1] , A[i][j - 1]};
                        
                        A[i][j] = *min_element(v.begin() , v.end()) + 1;
                        
                        result += A[i][j];
                    }
                    
                }
                
                
            }
        }
        return result;
    }
};
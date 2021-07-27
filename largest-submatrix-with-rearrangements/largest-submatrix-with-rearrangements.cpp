class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size() , m = matrix[0].size();
        int prefix[n][m];
        
        memset(prefix , 0 , sizeof(prefix));
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                
                if(!i){
                    prefix[i][j] = matrix[i][j];    
                    continue;
                }
                
                prefix[i][j] = (matrix[i][j]) ? prefix[i - 1][j] + 1 : 0;
            }
        }
        
        for(int i = 0 ; i < n ; i++)
            sort(prefix[i] , prefix[i] + m , greater<int>());
        
        int res = INT_MIN;
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                res = max(res , prefix[i][j] * (j + 1));
            }
        }
        
        return res;     // O(mnlogm)
    }
};
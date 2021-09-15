class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size() , m = matrix[0].size();
        
        int i = 0 , j = matrix[0].size() - 1;
        
        while(i < n){
            int curr = matrix[i][j];
            
            if(target == curr)
                return 1;
            
            if(target > curr){
                i++;
                continue;
            }
            
            return binary_search(matrix[i].begin() , matrix[i].end() , target);
        }
        return 0;
    }
};
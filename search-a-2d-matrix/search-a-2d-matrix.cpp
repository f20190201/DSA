class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        if(rows == 1 and cols == 1){
            if(target == matrix[0][0])
                return 1;
            else
                return 0;
            }
        int ptr = matrix[0][cols - 1];
        int curr_row = 0;
        int curr_col = cols-1;
        
        while(curr_row < rows && curr_col >= 0){
            ptr = matrix[curr_row][curr_col];
            
            if(target == ptr)
                return 1;
            
            if(target > ptr){
                curr_row++;
                continue;
            }
            else if(target < ptr){
                curr_col--;
            }
        }
        return 0;
    }
};
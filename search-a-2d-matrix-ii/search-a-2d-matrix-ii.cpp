class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        int curr_row = 0;
        int curr_col = cols - 1;
        
        int ptr = matrix[curr_row][curr_col];
        if(ptr == target)
            return 1;
        
        
        while(curr_col >= 0 and curr_row < rows){
            ptr = matrix[curr_row][curr_col];
            if(target == ptr)
                return 1;
            
            else if(target < ptr)
                curr_col--;
            
            else if(target > ptr)
                curr_row++;    
        }
        return 0;
        
            
    }
};
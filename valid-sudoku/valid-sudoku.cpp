class Solution {
public:
    bool isValid(vector<vector<char>>&A , int row , int col , char val){
        
        for(int i = 0 ; i < 9 ; i++){
            
            if(i != col && A[row][i] == val)
                return 0;
            
            if(i != row && (A[i][col] == val))
                return 0;
            
            int row_val = 3 * (row / 3) + (i / 3);
            int col_val = 3 * (col / 3) + (i % 3);
            if(!(row == row_val && col == col_val) && A[row_val][col_val] == val)
                return 0;
        }
        
        return 1;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        
        for(int i = 0 ; i < board.size() ; i++){
            for(int j = 0 ; j < board[0].size() ; j++){
                
                if(board[i][j] == '.')
                    continue;
                
                if(isValid(board , i , j , board[i][j]) == 0)
                    return 0;
            }
            
        }
        
        return 1;
    }
};
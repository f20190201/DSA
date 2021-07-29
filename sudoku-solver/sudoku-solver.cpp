class Solution {
public:
    bool isValid(vector<vector<char>>& board , char c , int i , int j){
        
        for(int k = 0 ; k < 9 ; k++){
            
            if(board[i][k] == c)
                return 0;
            
            if(board[k][j] == c)
                return 0;
            
            int row = 3 * (i / 3) + (k / 3);
            int col = 3 * (j / 3) + (k % 3);
            
            if(board[row][col] == c)
                return 0;
        }
        
        return 1;
        
    }
    
    bool solve(vector<vector<char>>& board , int i , int j){
        int n = board.size() , m = board[0].size();
        
        if(i == n)
            return 1;
        
        if(j == m)
            return solve(board , i + 1 , 0);
        
        if(board[i][j] != '.')
            return solve(board , i , j + 1);
        
        for (char c = '1' ; c <= '9' ; c++){
            
            if(isValid(board , c , i , j)){
                board[i][j] = c;
                
                if(solve(board , i , j + 1))
                    return 1;
                
                // else
                //     board[i][j] = '.';
            }
                   
        }
        
        board[i][j] = '.';
        
        return 0;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        solve(board , 0 , 0);
        
        return;
    }
};
class Solution {
public:

    bool isValid(vector<vector<char>>&A , int i , int j , char c){
        for(int k = 0 ; k < 9 ; k++){
            if(A[i][k] == c)
                return 0;
            
            if(A[k][j] == c)
                return 0;
            
            int row = 3 * (i / 3) + (k / 3);
            int col = 3 * (j / 3) + (k % 3);
            
            if(A[row][col] == c)
                return 0;
        }
        
        return 1;
    }
    
    bool solve(vector<vector<char>>&A , int i , int j){
        
        if(i == 9)
            return 1;
        
        if(j == 9)
            return solve(A , i + 1 , 0);
        
        if(A[i][j] != '.')
            return solve(A , i , j + 1);
        
        for(char c = '1' ; c <= '9' ; c++){
            
            if(isValid(A , i , j , c)){
                A[i][j] = c;
                
                if(solve(A , i , j + 1))
                    return 1;
                
                A[i][j] = '.';
            }
        }
        
        return 0;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        
        solve(board , 0 , 0);
        
        return;
    }
};
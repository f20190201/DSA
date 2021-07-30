class Solution {
public:
    int n , m;
    
    
    bool isValid(int i , int j){
        return (i >= 0 && i < n && j >= 0 && j < m);
    }
    
    bool solve(vector<vector<char>>& board , string word , int i , int j , int start){
        
         if(start == word.size())
            return 1;
        
        if(!isValid(i , j) || board[i][j] == '*')
            return 0;
        
        if(board[i][j] != word[start])
            return 0;
        
        char c = board[i][j];
        board[i][j] = '*';
        
        if(solve(board , word , i + 1 , j , start + 1) || solve(board , word , i , j + 1 , start + 1) || solve(board , word , i - 1 , j , start + 1) || solve(board , word , i, j - 1 , start + 1))
            
            return 1;
        
        board[i][j] = c;
        
        return 0;
    }
    
    
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size() , m = board[0].size();
        
        // vector<vector<int>>visited(n , vector<int>(m , 0));
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(solve(board , word , i , j , 0))
                    return 1;
            }
        }
        
        return 0;
    }
};
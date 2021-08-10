class Solution {
public:
    int m;
    vector<vector<string>> result;
    
    bool isSafe(vector<string>&v , int i , int j){
        for(int k = 0 ; k <= i ; k++)
            if(v[k][j] == 'Q')
                return 0;
        
        int row = i , col = j;
        
        while(row >= 0 && col >= 0){
            
            if(v[row][col] == 'Q')
                return 0;
            
            row--;
            col--;
        }
        
        row = i;
        col = j;
        
        while(row >= 0 && col < m){
            if(v[row][col] == 'Q')
                return 0;
            
            row--;
            col++;
        }
        
        return 1;
    }
    
    bool solve(vector<string>&v , int i){
        
        if(i == m){
            result.push_back(v);
            // return 1;
        }    
        
        for(int j = 0 ; j < m ; j++){
            
            if(isSafe(v , i , j)){
                v[i][j] = 'Q';
                
                if(solve(v , i + 1))
                    return 1;
                
                else
                    v[i][j] = '.';
            }
        }
        
        return 0;
    }
    
    vector<vector<string>> solveNQueens(int n) {
        m = n;
        result.clear();
        
        string s = "";
        
        for(int i = 0 ; i < m ; i++)
            s.push_back('.');
        
        vector<string> temp(m , s);
        
        solve(temp , 0);
        
        return result;
        
    }
};
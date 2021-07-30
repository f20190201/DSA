class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> A(n , vector<int>(n , 0));
        
        int top_row = 0 , bottom_row = n - 1 , left_col = 0 , right_col = n - 1;
        
        int num = 1;
        
        char flag = 'r';
        
        while(top_row <= bottom_row && left_col <= right_col){
            
            if(flag == 'r'){
                for(int i = left_col ; i <= right_col ; i++)
                    A[top_row][i] = (num++);
                
                top_row++;
                flag = 'd';
            }
            
            else if(flag == 'd'){
                for(int i = top_row ; i <= bottom_row ; i++)
                    A[i][right_col] = (num++);
                
                right_col--;
                flag = 'l';
            }
            
            else if(flag == 'l'){
                for(int i = right_col ; i >= left_col ; i--)
                    A[bottom_row][i] = (num++);
                
                bottom_row--;
                flag = 'u';
            }
            
            else if(flag == 'u'){
                for(int i = bottom_row ; i >= top_row ; i--)
                    A[i][left_col] = (num++);
                
                left_col++;
                flag = 'r';
            }
        }
        
        return A;
    }
};
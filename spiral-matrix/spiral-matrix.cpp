class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int top_row = 0 , bottom_row = matrix.size() - 1 , left_col = 0 , right_col = matrix[0].size() - 1;
        
        vector<int> res;
        
        char flag = 'r';
        
        while(top_row <= bottom_row && left_col <= right_col){
            
            if(flag == 'r'){
                for(int i = left_col ; i <= right_col ; i++)
                    res.push_back(matrix[top_row][i]);
                
                top_row++;
                flag = 'd';
            }
            
            else if(flag == 'd'){
                for(int i = top_row ; i <= bottom_row ; i++)
                    res.push_back(matrix[i][right_col]);
                
                right_col--;
                flag = 'l';
            }
            
            else if(flag == 'l'){
                for(int i = right_col ; i >= left_col ; i--)
                    res.push_back(matrix[bottom_row][i]);
                
                bottom_row--;
                flag = 'u';
            }
            
            else if(flag == 'u'){
                for(int i = bottom_row ; i >= top_row ; i--)
                    res.push_back(matrix[i][left_col]);
                
                left_col++;
                flag = 'r';
            }
            
        }
        
        return res;
    }
};
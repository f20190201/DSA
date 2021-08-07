class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size() , m = matrix[0].size();
        
        int i = 0 , j = m - 1;
        
        while(i < n && j >= 0){
            int num = matrix[i][j];
            
            if(target > num)
                i++;
            
            else if(target < num)
                j--;
            
            else
                return 1;
        }
        
        if(i == n || j == -1)
            return 0;
        
        return 0;
    }
};
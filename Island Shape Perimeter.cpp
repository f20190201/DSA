// Idea is to add 4 for every 1 encountered and subtract 1 for every neighbour

bool isNbr(vector<vector<int>>& matrix , int i , int j){
    int n = matrix.size() , m = matrix[0].size();

    return (i >= 0 && i < n && j >= 0 && j < m && matrix[i][j]);
}

int solve(vector<vector<int>>& matrix) {

    int perimeter = 0 , n = matrix.size() , m = matrix[0].size();

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(matrix[i][j]){
                perimeter += 4;

                perimeter -= (isNbr(matrix , i + 1 , j)) ? 1 : 0;
                perimeter -= (isNbr(matrix , i - 1 , j)) ? 1 : 0;
                perimeter -= (isNbr(matrix , i , j + 1)) ? 1 : 0;
                perimeter -= (isNbr(matrix , i , j - 1)) ? 1 : 0;
            }
        }
    }

    
    return perimeter;
        
}

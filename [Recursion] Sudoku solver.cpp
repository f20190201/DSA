bool isSafe(vector<vector<char> > &A , int row , int col , char val){

    for(int i = 0 ; i < 9 ; i++){
        if(A[row][i] == val)
            return 0;
        
        if(A[i][col] == val)
            return 0;
        
        if(A[3 * (row / 3) + (i / 3)][3 * (col / 3) + (i % 3)] == val)
            return 0;
    }
    return 1;
}

bool solve(vector<vector<char> > &A){
    int n = A.size();

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){

            if(A[i][j] == '.'){
                for(char k = '1' ; k <= '9' ; k++){
                    
                    if(isSafe(A , i , j , k)){
                        A[i][j] = k;
                        
                        if(solve(A))
                            return 1;
                        
                        else
                            A[i][j] = '.';
                    }

            
                }
                return 0;
            }

        }
    }

    return 1;
}

void Solution::solveSudoku(vector<vector<char> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    solve(A);
    return;
}

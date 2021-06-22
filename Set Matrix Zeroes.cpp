// We use the 1st column and row as the boolean array to check if 0s are present
// We take a variable col0 which tells us if the 1st column has any 0s
// If any element is 0, then we make the 1st row of that column and 1 column of that row as 0

void Solution::setZeroes(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    bool col0 = 1;
    int cols = A[0].size() , rows = A.size();

    for(int i = 0 ; i < rows ; i++){
        if(!A[i][0])
            col0 = 0;
        
        for(int j = 1 ; j < cols ; j++){
            if(!A[i][j])
                A[0][j] = A[i][0] = 0;
        }
    }
    for(int i = rows - 1 ; i >= 0 ; i--){
        

        for(int j = cols - 1 ; j >= 1 ; j--){
            if(A[i][0] == 0 or A[0][j] == 0)
                A[i][j] = 0;
        }
        if(!col0) A[i][0] = 0;
    }
    return;

}

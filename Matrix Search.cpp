bool search(vector<int> &A , int B){
    int low = 0;
    int high = A.size() - 1;
    int mid = low + (high - low) / 2;

    while(low <= high){
        mid = low + (high - low) / 2;
        
        if(A[mid] == B)
            return 1;

        else if(A[mid] < B)
            low = mid + 1;

        else
            high = mid - 1; 
    }

return 0;


}



int Solution::searchMatrix(vector<vector<int> > &A, int B) {
    int rows = A.size();
    int cols = A[0].size();

    if(rows == 1 and cols == 1){
        if(B == A[0][0])
            return 1;
        return 0;
    }
    if(B > A[rows - 1][cols - 1])
        return 0;
    
    int curr_row = 0 , curr_col = cols - 1;  

    while(curr_row < rows){
        if(A[curr_row][curr_col] < B)
            curr_row++;
        else
            break;
    }
    
    return search(A[curr_row] , B);



}

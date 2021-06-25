// Scan from the right and find the 1st digit which isn't in ascending order, if no such digit exists, return -1
// This is the digit which needs to be swapped with the nearest greater digit to its right
// After swapping, sort the subtsring to the right of the initial index, in the ascending order.

string Solution::solve(string A) {
    int N = A.size();

    if(count(A.begin() , A.end() , A[0]) == N)
        return "-1";
    
    int i;
    bool flag = 0;

    for(i = N-1 ; i > 0 ; i--){
        if(A[i] - A[i-1] > 0){
            i--;
            break;
        }
        if(i == 1)
            return "-1";
    }    
    
    
    int toBeSwapped = i+1;

    for(int j = i+1 ; j < N ; j++){
        if(A[j] > A[i] and A[j] < A[toBeSwapped])
            toBeSwapped = j;
    }

    int temp = A[i];
    A[i] = A[toBeSwapped];
    A[toBeSwapped] = temp;

    sort(A.begin() + i + 1 , A.end());

    //reverse(A.begin() , A.end());
 
    return A;

}

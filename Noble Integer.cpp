// Sort array in descending order
// If there are no duplicates, then there exists a noble integer if index == value
// If there are duplicates, but the first instance of a duplicate number satisfies the condition, then also noble integer exists,
// since the 1st instance of that number is as good as being unique
// For checking that duplicate number doesn't give the false correct, we check if the previous number is same as the current number


int Solution::solve(vector<int> &A) {
    sort(A.begin() , A.end() , greater<int>());


    if(A[0] == 0)
        return 1;

    for(int i = 0 ; i < A.size() ; i++){
        if((i != 0) and (i == A[i]) and (A[i] != A[i-1]))
            return 1;
        

    }
    return -1;

}

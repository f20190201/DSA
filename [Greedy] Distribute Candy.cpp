// Divide the left and right check into 2 parts
// First check for the currect element with its left
// Then check for the current element with its right
// Finally add the max of both to total

int Solution::candy(vector<int> &A) {
    int count = 0 , prev = A[0] , lastMin = 1;
    vector<int> lr(A.size() , 1);
    vector<int> rl(A.size() , 1);

    for(int i = 1 ; i < A.size() ; i++){
        if(A[i] > A[i - 1])
            lr[i] = lr[i - 1] + 1;
    }
    for(int i = A.size() - 2 ; i >= 0 ; i--){
        if(A[i] > A[i + 1])
            rl[i] = rl[i + 1] + 1;
    }

    for(int i = 0 ; i < A.size() ; i++)
        count += max(lr[i] , rl[i]);

    return count;

}

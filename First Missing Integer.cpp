// Every number less than 1 and greater than N is changed to 1
// Idea is to mark each number for its presence by increasing it by N
// The answer always lies between 1 and N+1

int Solution::firstMissingPositive(vector<int> &A) {
    bool flag = 0;
    int N = A.size();

    for(int i = 0 ; i < N ; i++){
        if(A[i] == 1){
            flag = 1;
            break;
        }
    }

    if(flag == 0)
        return 1;
    
    for(int i = 0 ; i < N ; i++){
        
        if(A[i] < 1 or A[i] > N)
            A[i] = 1;
        
    }

    for(int i = 0 ; i < N ; i++){
      // 1 has been subtracted because if all positive numbers are places sequentially, 4 would occupy A[3], since index start from 0 and +ve nos from 1
        A[(A[i] - 1) % N] += N;
    }

    for(int i = 0 ; i < N ; i++)
        if(A[i] <= N)
            return i + 1;
        
    return N + 1;
    
}

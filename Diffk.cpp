// Take 2 pointers i and j with i being ahead of j
// If both are equal, advance i
// If difference is less than B, advance i
// If difference is more than B, advance j

int Solution::diffPossible(vector<int> &A, int B) {
    int i = 1 , j = 0 , N = A.size();

    while(i < N and j < N){
        
        if(i == j){
            i++;
            continue;
        }
        
        int diff = A[i] - A[j];
        
        if(diff == B and (i != j))
            return 1;
        else if(diff < B)
            i++;
        else
            j++;
    }

    return 0;

}

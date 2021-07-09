// Since the numbers present are 1 to N in an array of N, the right place of element N - i is (N - i)th index.
// If an element is present at its right position, do nothing. Else, swap it with element that should be present

vector<int> Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    vector<int> pos(n + 1);

    for(int i = 0 ; i < n ; i++){
        pos[A[i]] = i;
    }

    for(int i = 0 ; i < n ; i++){
        
        if(!B)
            break;
        
        if(A[i] == n - i)
            continue;
        
        int temp = pos[n - i];

        pos[A[i]] = pos[n - i];
        pos[n - i] = i;
        
        swap(A[i] , A[temp]);

        B--;
    }
    return A;

}

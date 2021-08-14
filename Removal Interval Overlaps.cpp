// To remove minimum intervals, if we find start of current is greater than minimum end till now, remove the interval which has minimum interval
// In other cases, we update min_end as the end of current interval

// https://binarysearch.com/problems/Remove-Interval-Overlaps

int solve(vector<vector<int>>& A) {
    int n = A.size() , count = 0;
    
    if (!n)
        return 0;
    
    sort(A.begin(), A.end());

    int min_end = A[0][1];

    for (int i = 1; i < n; i++) {
        
        if(A[i][0] < min_end){
            count++;
            min_end = min(min_end , A[i][1]);
            continue;
        }

        min_end = A[i][1];
    }

    return count;
}

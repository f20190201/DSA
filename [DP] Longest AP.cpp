// We find if any other element exists with the same difference and ending with the same value
// https://www.youtube.com/watch?v=Lm38EAoDc7c

int Solution::solve(const vector<int> &A) {
    int n = A.size();

    if(n <= 2)
        return n;
    
    vector<map<int , int>> t(n);

    int max_len = 2;

    for(int i = 0 ; i < n ; i++){

        for(int j = i + 1 ; j < n ; j++){
            int d = A[j] - A[i];

            if(t[i].find(d) != t[i].end())
                t[j][d] = t[i][d] + 1;
            
            else
                t[j][d] = 2;
            
            max_len = max(t[j][d] , max_len);
        }
    }
    return max_len;
}

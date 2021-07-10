int Solution::jump(vector<int> &A) {
    const int sz = A.size();
    
    // // Greedy Ver.
    if (sz == 1) return 0;
    int maxRange = A[0];
    int updatedMaxRange = A[0];
    int numSteps = 1;
    for (int i = 0; i < sz; i++) {
        if (i + A[i] > updatedMaxRange) {
            updatedMaxRange = i + A[i];
        }
        
        if (i == sz -1) {
            if (updatedMaxRange < sz) {
                break;
            }
            return numSteps;
        }
        
        if (i == maxRange) {
            if (updatedMaxRange == maxRange) {
                return -1;
            }
            numSteps++;
            maxRange = updatedMaxRange;
        }
    }
    return -1;
   
}


------------------------------------------------------------------------------------------------------------------------------
  
  
  int Solution::jump(vector<int> &A) {
    int n = A.size();
    vector<int> t(n , INT_MAX);
    t[0] = 0;

    for(int i = 1 ; i < n ; i++){
        
        for(int j = 0 ; j < i ; j++){
            if(t[j] == INT_MAX)
                return -1;
            if(i <= (j + A[j]))
                t[i] = min(t[i] , t[j] + 1);
        }
    }

    if(t[n - 1] == INT_MAX)
        return -1;
    
    return t[n - 1];

}

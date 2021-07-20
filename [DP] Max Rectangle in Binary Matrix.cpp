int MAH(vector<int>A){
    int n = A.size();
    vector<int> NSL(n , -1) , NSR(n , n);
    stack<int> s;
    
    for(int i = 0 ; i < n ; i++){
        
        while(!s.empty() && A[s.top()] >= A[i])
            s.pop();
        
        if(!s.empty())
            NSL[i] = s.top();
        
        s.push(i);
    } 

    while(!s.empty())
        s.pop();

    for(int i = n - 1 ; i >= 0 ; i--){

        while(!s.empty() && A[s.top()] >= A[i])
            s.pop();
        
        if(!s.empty())
            NSR[i] = s.top();
        
        s.push(i);
    }

    int res = INT_MIN;

    for(int i = 0 ; i < n ; i++){
        int temp = A[i] * (NSR[i] - NSL[i] - 1);
        res = max(temp , res);
    }

    return res;
}

int Solution::maximalRectangle(vector<vector<int> > &A) {
    int n = A.size() , m = A[0].size() , ans = 0;
    
    vector<int> hist(m);

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){

            if(A[i][j] == 0)
                hist[j] = 0;
            
            else
                hist[j] += A[i][j];

        }

        ans = max(ans , MAH(hist));
    }
    return ans;
}

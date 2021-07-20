Using prefix sum array, try to convert it into the 1D method
// https://www.youtube.com/watch?v=elADMOC_hDI

int Solution::solve(vector<vector<int> > &A) {
    if(A.size() == 0)
        return 0;
    
    int n = A.size() , m = A[0].size();

    int preSum[n + 1][m];

    for(int j = 0 ; j < m ; j++){
        for(int i = 0 ; i < n ; i++)
            preSum[i + 1][j] = preSum[i][j] + A[i][j];
    }

    map<int , int> mp;
    int ans = 0;

    for(int i = 0 ; i < n ; i++){
        for(int k = i ; k < n ; k++){
            mp.clear();
            int sum = 0;

            for(int j = 0 ; j < m ; j++){
                sum += preSum[k + 1][j] - preSum[i][j];

                if(sum == 0)
                    ans++;
                
                if(mp.count(sum - 0))
                    ans += mp[sum];
                
                mp[sum]++;
            }
        }

    }
    return ans;

}

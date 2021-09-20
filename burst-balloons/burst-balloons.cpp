class Solution {
public:
    int maxCoins(vector<int>& dims) {
        // insert 1 at begin and end
        dims.insert(dims.begin(), 1);
        dims.push_back(1);
        
        int n = dims.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // initialize for d=0 (along the diagonal): already done
        // for(int i=0; i<n; i++) dp[i][i] = dims[i];

        for(int len=1; len<n; len++){
            for(int i=1; i<n-len; i++){
                int j = i+len;
                int min_cost = INT_MIN;

                for(int k=i; k<j; k++){
                    int cost = dp[i][k] + dp[k+1][j] + dims[i-1]*dims[k]*dims[j];
                    min_cost = max(min_cost, cost);
                }
                dp[i][j] = min_cost;
            }
        }
        
        
        return dp[1][n-1];
    }
};
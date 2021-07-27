class Solution {
public:
    int dp[201][201];
    vector<vector<int>>A;
    
    int solve(int i , int j){
        
        if(i == A.size() || j == A[0].size())
            return INT_MIN / 10;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        // cost = min(A[i][j] , cost + A[i][j]);
        
        if(i == A.size() - 1 && j == A[0].size() - 1){
            return dp[i][j] = A[i][j];
        }
        
        
        int right = solve(i , j + 1);
        int down = solve(i + 1 , j);
        
        return dp[i][j] =  min(A[i][j] , A[i][j] + max(right , down));
        
    }
    
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        A = dungeon;
        memset(dp , -1 , sizeof(dp));
        int ans = solve(0 , 0);
        if(ans > 0)
            return 1;
        return 1 - ans;
    
        
    }
};
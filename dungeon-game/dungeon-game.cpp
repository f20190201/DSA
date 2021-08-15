class Solution {
public:
    vector<vector<int>> A;
    int n , m;
    
    int dp[201][201];
    
    int solve(int i , int j){
        
        if(i < 0 || i >= n || j < 0 || j >= m)
            return INT_MIN;
        
        if(dp[i][j] != 1001)
            return dp[i][j];
        
        if(i == n - 1 && j == m - 1)
            return dp[i][j] = A[i][j];
        
        int down = solve(i + 1 , j);
        int right = solve(i , j + 1);
        
        return dp[i][j] = min(A[i][j] , A[i][j] + max(down , right));
        
        
    }
    
    
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        A = dungeon;   
        n = dungeon.size();
        m = dungeon[0].size();
        
        for(int i = 0 ; i < 201 ; i++){
            for(int j = 0 ; j < 201 ; j++)
                dp[i][j] = 1001;
        }
        
        int ans = solve(0 , 0);
        
        if(ans > 0)
            return 1;
        
        return (1 - ans);
    }
};
class Solution {
public:
    int dp[201][201][201];
    bool solve(string s1, string s2, string s3 , int index , int i , int j){
        
        if(index == s3.size()){
            if(i == s1.size() && j == s2.size())
                return 1;
            return 0;
        }
        
        if(dp[index][i][j] != -1)
            return dp[index][i][j];
        
        if(s1[i] == s3[index] && s2[j] == s3[index])
            return dp[index][i][j] = (solve(s1 , s2 , s3 , index + 1 , i , j + 1) || solve(s1 , s2 , s3 , index + 1 , i + 1 , j));
        
        if(s1[i] == s3[index])
            return dp[index][i][j] = solve(s1 , s2 , s3 , index + 1 , i + 1 , j);
        
        if(s2[j] == s3[index])
            return dp[index][i][j] = solve(s1 , s2 , s3 , index + 1 , i , j + 1);
        
        return dp[index][i][j] = 0;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        memset(dp , -1 , sizeof(dp));
        
        return solve(s1 , s2 , s3 , 0 , 0 , 0);
    }
};
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


-------------------------------------------------------------------------------------------------------------------------------------

    
class Solution {
public:
    int dp[201][201];
    
    bool isInterleave(string s1, string s2, string s3) {
        
        if((s1.size() + s2.size()) != s3.size())
            return 0;
        
        memset(dp , -1 , sizeof(dp));
        
        dp[0][0] = 1;
        
        for(int i = 1 ; i <= s1.size() ; i++){
            dp[i][0] = (s3[i - 1] == s1[i - 1]) ? dp[i - 1][0] : 0;
        }
        
        for(int j = 1 ; j <= s2.size() ; j++)
            dp[0][j] = (s3[j - 1] == s2[j - 1]) ? dp[0][j - 1] : 0;
        
        for(int i = 1 ; i <= s1.size() ; i++){
            for(int j = 1 ; j <= s2.size() ; j++){
                
                if(s1[i - 1] == s3[i + j - 1] && s2[j - 1] == s3[i + j - 1])
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                
                else if(s1[i - 1] == s3[i + j - 1])
                    dp[i][j] = dp[i - 1][j];
                
                else if(s2[j - 1] == s3[i + j - 1])
                    dp[i][j] = dp[i][j - 1];
                
                else
                    dp[i][j] = 0;
                
            }
        }
        return dp[s1.size()][s2.size()];
    }
};

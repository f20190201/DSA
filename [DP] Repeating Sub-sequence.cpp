// Pass the same string in LCS, just make sure index aren't same

int LCS(string s1 , string s2){
    int n1 = s1.size() , n2 = s2.size();

    int t[n1 + 1][n2 + 1];
    memset(t , 0 , sizeof(t));

    for(int i = 1 ; i <= n1 ; i++){
        for(int j = 1 ; j <= n2 ; j++){
            
            if(s1[i - 1] == s2[j - 1] and (i != j))
                t[i][j] = 1 + t[i - 1][j - 1];
            
            else
                t[i][j] = max(t[i - 1][j] , t[i][j - 1]);
        }
    }

    return (t[n1][n2] > 1);

}

int Solution::anytwo(string A) {
    

    return LCS(A , A);
    
}

int dist(string s1 , string s2){
    int n1 = s1.size() , n2 = s2.size();

    int t[n1 + 1][n2 + 1];

    memset(t , 0 , sizeof(t));

    for(int i = 0 ; i <= n1 ; i++){
        t[i][0] = i;
    }

    for(int i = 0 ; i <= n2 ; i++){
        t[0][i] = i;
    }

    for(int i = 1 ; i <= n1 ; i++){
        for(int j = 1 ; j <= n2 ; j++){
            if(s1[i - 1] == s2[j - 1])
                t[i][j] = t[i - 1][j - 1];
            
            else
                t[i][j] = 1 + min(t[i-1][j] , min(t[i][j-1] , t[i - 1][j - 1]));
        }
    }
    return t[n1][n2];
}

int Solution::minDistance(string A, string B) {

    return dist(A , B);
}

long long numberOfWays(int coins[],int numberOfCoins,int value)
    {
        int n = numberOfCoins;
        long long t[n+1][value+1];
        
        for(int i = 0 ; i <= n ; i++)
            t[i][0] = 1;
        
        for(int j = 0 ; j <= value ; j++)
            t[0][j] = 0;
        
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= value ; j++){
                if(coins[i-1] <= j)
                    t[i][j] = t[i][j - coins[i-1]] + t[i-1][j];
                
                else
                    t[i][j] = t[i-1][j];
            }
        }
        return t[n][value];
    }

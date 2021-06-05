long long minimumNumberOfCoins(int coins[],int numberOfCoins,int value)
    {
        // your code here
        int n = numberOfCoins;
        long long t[n+1][value+1];
        
        for(int i = 0 ; i <= n ; i++)
            t[i][0] = 0;
        
        for(int j = 0 ; j <= value ; j++)
            t[0][j] = INT_MAX - 1;
     
  // In this dp table, the 2nd row has also been initialised. If the value divides the coin value, then the quotient is t[i][j]
  // If remainder exists then INT_MAX-1 is put as t[i][j]
  
        for(int j = 1 ; j <= value ; j++){
            if((j % coins[0]) == 0)
                t[1][j] = j / coins[0];
            else
                t[1][j] = (INT_MAX - 1);
        }
            
        
        for(int i = 2 ; i <= n ; i++){
            for(int j = 1 ; j <= value ; j++){
                    if(coins[i-1] <= j)
                        t[i][j] = min(1 + t[i][j - coins[i-1]] , t[i-1][j]);
                    
                    else
                        t[i][j] = t[i-1][j];
                
            }
        }
        long long ans = t[n][value];
        
        if((ans == INT_MAX - 1) ||(ans == INT_MAX) ||(ans == 0))
            return -1;
        
        return ans;
    }

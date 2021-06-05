int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       int t[n+1][W+1];
       
       for(int i = 0 ; i <= n ; i++)
        t[i][0] = 0;
       
       for(int j = 0 ; j <= W ; j++)
        t[0][j] = 0;
        
       for(int i = 1 ; i <= n ; i++){
           for(int j = 1 ; j <= W ; j++){
               if(wt[i-1] <= j)
                t[i][j] = max(val[i-1] + t[i-1][j - wt[i-1]] , t[i-1][j]);
            
               else
                t[i][j] = t[i-1][j];
           }
       }
       
       return t[n][W];
    }

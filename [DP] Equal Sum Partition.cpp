bool findPartition(int a[], int n)
    {
        // code here
        int sum = 0;
        
        for(int i = 0 ; i < n ; i++)
            sum+=a[i];
        
        if(sum % 2)
            return 0;
 
  // Following is the subset sum problem with n = n and sum = sum/2
  
        bool t[n+1][(sum/2)+1];
        
        for(int j = 1 ; j <= (sum/2) ; j++)
            t[0][j] = 0;
        
        for(int i = 0 ; i <= n ; i++)
            t[i][0] = 1;
        
        for(int i = 1 ; i <= n ; i++ ){
            for(int j = 1 ; j <= (sum/2) ; j++){
                if(a[i-1] <= j)
                    t[i][j] = (t[i-1][j - a[i-1]]) || (t[i-1][j]);
                else
                    t[i][j] = t[i-1][j];
            }
        }
        return t[n][sum/2];
        
    }

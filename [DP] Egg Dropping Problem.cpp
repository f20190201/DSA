int dp[10001][101];
    int sol(int k,int n){
        if(k==1||n==1) return n;
        if(dp[n][k]!=-1) return dp[n][k];
        
        int ans=n,l=1,h=n;
        while(l<=h)
        {
            int mid=(l+h)/2;
            int left=sol(k-1,mid-1);   //egg broken check for down floors of mid
            int right=sol(k,n-mid) ;   // not broken check for up floors of mid
            int temp=1+max(left,right);          //store max of both 
            if(left<right){                  //since right is more than left and we need more in wrost case
              l=mid+1;                       // so l=mid+1 to gain more temp for worst case: upward
            }
            else                             //left > right so we will go downward 
            {    
                h=mid-1;
            }
            ans=min(ans,temp);               //store minimum attempts
        }
        
        return dp[n][k]=ans;
    }
    int eggDrop(int n, int k) { 
        memset(dp,-1,sizeof dp);
        return sol(n,k);
    }


-----------------------------------------------------------------------------
    
    
    int eggDrop(int n, int k) 
    {
        // your code here
        int t[n+1][k+1];
        
        
        for(int i = 0 ; i <= n ; i++){
            t[i][0] = 0;
            t[i][1] = 1;
        }
            
        for(int j = 0 ; j <= k ; j++){
            t[1][j] = j;
        }
        
        for(int i = 2 ; i <= n ; i++){
            for(int j = 2 ; j <= k ; j++){
                t[i][j] = INT_MAX;
                
                for(int x = 1 ; x <= j ; x++){
                int result = 1 + max(t[i-1][x-1] , t[i][j - x]);
                t[i][j] = min(t[i][j] , result);
                }
                
            }
        }
        
        return t[n][k];
    }

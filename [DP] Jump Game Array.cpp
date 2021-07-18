int Solution::canJump(vector<int> &A) {
    int n = A.size();
    int dp[n];
    memset(dp , 0 , sizeof(dp));
    dp[0] = 1;

    for(int i = 0 ; i < n ; i++){
        
        if(dp[i] == 0)
            return 0;

        for(int j = 0 ; j <= A[i] ; j++){
            
            if(i + j >= n - 1){
                // cout<<i<<" , "<<j<<endl;
                return 1;
            }
            
            dp[i + j] = 1;
        }
    }

    return dp[n - 1];


}

-------------------------------------------------------------------------------------------
  
  
  int Solution::canJump(vector<int> &A) {
int n=A.size();
int target=n-1;
for(int i=n-2;i>=0;i--){
 if(A[i]+i>=target){//that is if we can reach target from i 
     target=i;       // then our job is to just reach i
 }   
}
return target==0; // if we there is a way from 0 to n-1 then we will definitely end up 
                // at 0

}

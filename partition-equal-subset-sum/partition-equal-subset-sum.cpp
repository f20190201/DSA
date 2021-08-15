class Solution {
public:
//     int dp[201][20001];
    
//     bool solve(vector<int>& A , int sum , int temp , int index){
        
//         if(index == A.size()){
//             if(temp == sum)
//                 return 1;
//             return 0;
//         }
        
//         if(dp[index][temp] != -1)
//             return dp[index][temp];
        
//         if(temp > sum)
//             return 0;
        
//         return dp[index][temp] = solve(A , sum , temp , index + 1) || solve(A , sum , temp + A[index] , index + 1);
//     }
    
    
    bool canPartition(vector<int>& nums) {
        int n = nums.size() , sum = 0;
        
//         memset(dp , -1 , sizeof(dp));
        
        for(auto x : nums)
            sum += x;
        
        if(sum % 2 != 0)
            return 0;
        
        sum = sum / 2;
        
        int dp[n + 1][sum + 1];
        
        for(int i = 0 ; i <= n ; i++)
            dp[i][0] = 1;
        
        for(int j = 1 ; j <= sum ; j++)
            dp[0][j] = 0;
        
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= sum ; j++){
                
                if(nums[i - 1] <= j)
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
                
                else
                    dp[i][j] = dp[i - 1][j];    
                
            }
        }
        
        return dp[n][sum];
        
//         return solve(nums , sum , 0 , 0);
    }
};

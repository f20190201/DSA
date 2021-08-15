class Solution {
public:
    int dp[101][10001];
    
    int solve(int eggs , int floor){
        
        if(eggs == 1 || floor == 1)
            return floor;
        
        if(dp[eggs][floor] != -1)
            return dp[eggs][floor];
        
        int low = 1 , high = floor , ans = floor;
        
        while(low <= high){
            int mid = (low + high) / 2;
            
            int up = solve(eggs , floor - mid);
            int down = solve(eggs - 1 , mid - 1);
            
            int temp = 1 + max(up , down);
            
            if(up < down){
                high = mid - 1;
            }
            
            else
                low = mid + 1;
            
            ans = min(ans , temp);
        }
        
        return dp[eggs][floor] = ans;
    }
    
    int superEggDrop(int k, int n) {
        memset(dp , -1 , sizeof(dp));
        
        return solve(k , n);
    }
};
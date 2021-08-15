class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        int dp[n + 1];
        
        int maxSell = prices[n - 1];
        
        dp[n - 1] = 0;
        
        for(int i = n - 2 ; i >= 0 ; i--){
            dp[i] = max(dp[i + 1] , maxSell - prices[i]);
            
            maxSell = max(maxSell , prices[i]);
        }
        
        int minBuy = prices[0];
        
        for(int i = 1 ; i < n ; i++){
            dp[i] = max(dp[i - 1] , dp[i] + prices[i] - minBuy);
            
            minBuy = min(minBuy , prices[i]);
        }
        
        int ans = 0;
        
        for(int i = 0 ; i < n ; i++)
            ans = max(ans , dp[i]);
        
        return ans;
    }
};
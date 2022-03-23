class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size() , maxPrice = INT_MIN , maxProfit = 0;
        
        for(int i = n - 1 ; i >= 0 ; i--){
            
            if(prices[i] > maxPrice)
                maxPrice = prices[i];
            
            maxProfit = max(maxProfit , maxPrice - prices[i]);
        }
        
        return max(0 , maxProfit);
    }
};
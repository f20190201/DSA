class Solution {
public:
    int maxProfit(vector<int> &A) {
        
        int n = A.size();
        
        vector<int>v(n);
        
        int maximum = INT_MIN;
        
        for(int i = n - 1 ; i >= 0 ; i--){
            
            if(A[i] > maximum)
                maximum = A[i];
            
            v[i] = maximum;
        }
        
        int profit = INT_MIN;
        
        for(int i = 0 ; i < n - 1 ; i++){
            int temp = v[i + 1] - A[i];
            
            profit = max(temp , profit);
        }
        
        if(profit < 0)
            return 0;
        
        return profit;
        
    }
};
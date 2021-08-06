class Solution {
public:
    int maxProfit(vector<int> &A) {
        
        int ans = 0 , minPrice = INT_MAX;
        
        for(int i = 0 ; i < A.size() ; i++){
            minPrice = min(minPrice , A[i]);
            ans = max(ans , A[i] - minPrice);
        }
        
        return ans;
    }
};
class Solution {
public:
    int amt(vector<int>& cost , int n){
        
        // return cost[start] + min(amt(cost , start + 1 , n) , amt(cost , start + 2 , n));
        if(n == 2)
            return cost[0];
        
        int t[n + 1];
        
        t[0] = 0;
        t[1] = cost[0];
        
        for(int i = 2 ; i <= n ; i++){
            t[i] = min(cost[i - 1] + t[i - 1] , cost[i - 2] + t[i - 2]);
        }
        
        return t[n];
    }
    
    
    int minCostClimbingStairs(vector<int>& cost) {
        
        vector<int> v1;
        
        v1.assign(cost.begin() + 1 , cost.end());
        
        return min(amt(cost , cost.size()) , amt(v1 , v1.size()));
    }
};
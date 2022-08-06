class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        
        bool canReach[n];
        memset(canReach , 0 , sizeof(canReach));
        canReach[0] = 1;
        
        for(int i = 0 ; i < n ; i++){
            
            if(canReach[i] == 0)
                return 0;
            
            int startPos = i , endPos = min(n - 1 , i + nums[i]);
            
            for(int j = startPos ; j <= endPos ; j++)
                canReach[j] = 1;
        }
        
        return canReach[n - 1];
    }
};
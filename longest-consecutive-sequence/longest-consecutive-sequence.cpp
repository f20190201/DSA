class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int , int> mp;
        int ans = 0 , temp = 0 , num;
        
        for(int i = 0 ; i < nums.size() ; i++)
            mp[nums[i]]++;
        
        for(int i = 0 ; i < nums.size() ; i++){
            
            num = nums[i];
            
            if(mp.count(num - 1))
                continue;
            
            temp = 0;
            
            while(mp.count(num)){
                temp++;
                num++;
            }
            ans = max(ans , temp);
        }
            
        return ans;
    }
};
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char , int>mp;
        int maxCount = 0 , ans = 0;
        
        for(int i = 0 ; i < tasks.size() ; i++){
            mp[tasks[i]]++;
            maxCount = max(maxCount , mp[tasks[i]]);
        }
        
        ans = (maxCount - 1) * (n + 1);
        
        for(auto it : mp){
            if(it.second == maxCount)
                ans++;
        }
        
        return max((int)tasks.size() , ans);
    }
};
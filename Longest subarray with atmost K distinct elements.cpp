// Use variable size sliding window
// If mp.size() <= k, consider it to be a potential answer
// Else, remove elements till mp.size() <= k

int solve(int k, vector<int>& nums) {
    int n = nums.size();
    int i = 0 , j = 0 , ans = 0;
    unordered_map<int , int>mp;

    while(j < n){
        mp[nums[j]]++;

        if(mp.size() <= k){
            ans = max(ans , j - i + 1);
        }

        while(i <= j && mp.size() > k){
            mp[nums[i]]--;
            if(mp[nums[i]] == 0)
                mp.erase(nums[i]);
            
            i++;
        }

        j++;
    }

    return ans;
}

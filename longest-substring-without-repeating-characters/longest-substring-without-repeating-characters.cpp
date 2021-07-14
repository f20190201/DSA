class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char , int>mp;
        
        int i = 0 , j = 0 , n = s.size();
        int result = 0;
        
        while(j < n){
            
            mp[s[j]]++;
            
            if(mp.size() >= (j - i + 1)){
                result = max(result , (j - i + 1));
            }
            
            while(mp.size() < (j - i + 1)){
                mp[s[i]]--;
                
                if(mp[s[i]] == 0)
                    mp.erase(s[i]);
                
                i++;
            }
            
            j++;
        }
        
        return result;
    }
};


-----------------------------------------------------------------------------------------------------------------------

int lengthOfLongestSubstring(string s) {
        vector<int> dict(256, -1);
        int maxLen = 0, start = -1;
        for (int i = 0; i != s.length(); i++) {
            if (dict[s[i]] > start)
                start = dict[s[i]];
            dict[s[i]] = i;
            maxLen = max(maxLen, i - start);
        }
        return maxLen;
    }

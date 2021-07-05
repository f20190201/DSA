// Sliding Window + Maps
// If size of window == maps.size(), then we have an answer.
// Till size of window == maps.size(), we increment j.
// When we encounter a duplicate, we increment i, after reducing the count of mp[A[i]] in the map. If count is 0, then we erase it from the map.

int Solution::lengthOfLongestSubstring(string A) {
    map<char , int>mp;
    int ans = 0;
    int i = 0 , j = 0 , n = A.size();

    while(j < n){
        // int window = j - i + 1;

        mp[A[j]]++;

        if(j - i + 1 == mp.size()){
            ans = max(ans , j - i + 1);
        }

        while(mp.size() < j - i + 1){
            mp[A[i]]--;
            if(mp[A[i]] == 0)
                mp.erase(A[i]);
            i++;
        }

        j++;

    }

    return ans;

}

int solve(string a, string b) {
    map<char , int>mp , mp1;

    int n = b.size();

    for(int i = 0 ; i < n ; i++)
        mp[b[i]]++;

    int i = -1 , j = 0 , m = a.size() , matchCount = 0;
    int ans = INT_MAX;

    while(1){
        bool flag1 = 0 , flag2 = 0;
        //expand window till you reach the first ans
        while(j < m && matchCount < n){
            flag1 = 1;
            mp1[a[j]]++;

            if(mp1[a[j]] <= mp[a[j]])
                matchCount++;
            
            j++;
        }
        
        //we have got our first ans and now time to decrease the window

        while(i < j && matchCount == n){
            flag2 = 1;
            i++;

            ans = min(ans , j - i);

            mp1[a[i]]--;

            if(mp1[a[i]] < mp[a[i]])
                matchCount--;
            
            if(mp1[a[i]] == 0)
                mp1.erase(a[i]);
            
        }

        if(flag1 == 0 && flag2 == 0)
            break;

    }

    if(ans == INT_MAX)
        return -1;

    return ans;    
}

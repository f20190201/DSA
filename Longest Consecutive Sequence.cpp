int Solution::longestConsecutive(const vector<int> &A) {
    
    if(A.size() == 0)
        return 0;
    
    unordered_set<int>s;
    
    for(auto i: A)
        s.insert(i);

    int ans = 0;

    while(!s.empty())
    {
        int x = *s.begin();
        s.erase(x);
        int i = x-1;
        int count = 1;

        while(s.find(i) != s.end())
        {

            ++count;
            s.erase(i);
            --i;

        }

        i = x+1;

        while(s.find(i) != s.end())
        {

            ++count;
            s.erase(i);
            ++i;

        }

        ans = max(ans, count);

    }

    return ans;

}

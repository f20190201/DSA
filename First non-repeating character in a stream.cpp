string Solution::solve(string A) {
    vector<int>v(26 , 0);
    queue<char>q;
    string s = "";

    for(int i = 0 ; i < A.size() ; i++){
        
        v[A[i] - 'a']++;
        q.push(A[i]);

        while(!q.empty() and v[q.front() - 'a'] > 1){
            q.pop();
        }
        
        if(!q.empty())
            s += q.front();
        else
            s += '#';
    }

    return s;


}

----------------------------------------------
  
  string Solution::solve(string A) {
    
    unordered_map<char, int> mp;
    queue<char> q;
    
    string ans;
    
    for (auto c : A)
    {
        mp[c]++;
        q.push(c);
      
        while (!q.empty() && mp[q.front()] > 1)
            q.pop();

        if (!q.empty())
            ans.push_back(q.front());

        else
            ans.push_back('#');
    }
    return ans;
}

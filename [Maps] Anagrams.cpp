// If we sort a string, that string and all its anagrams would be same

vector<vector<int> > Solution::anagrams(const vector<string> &A) {
    vector<vector<int>> result;
    unordered_map<string , vector<int>>mp;

    for(int i = 0 ; i < A.size() ; i++){
        string s = A[i];
        
        sort(s.begin() , s.end());

        mp[s].push_back(i + 1);

    }

    for(auto x : mp){
        result.push_back(x.second);
    }
    return result;

}

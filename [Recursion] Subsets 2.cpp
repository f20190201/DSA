vector<vector<int>> result;

void solve(vector<int> &A , vector<int> &v , int index){
    if(index == A.size()){
        
        result.push_back(v);

        return;
    }

    v.push_back(A[index]);
    
    solve(A , v , index + 1);
    
    v.pop_back();
    
    solve(A , v , index + 1);

    return;
}

vector<vector<int> > Solution::subsetsWithDup(vector<int> &A) {
    result.clear();

    sort(A.begin() , A.end());

    vector<int> v;

    solve(A , v , 0);

    set<vector<int>>s;

    for(auto x : result)
        s.insert(x);
    
    result.clear();

    for(auto it = s.begin() ; it != s.end() ; ++it)
        result.push_back(*it);
    
    return result;

}

vector<vector<int>>result;

void solve(vector<int> &v , int i , int n , int k){
    if(i == (n + 1)){
        
        if(k == 0)
            result.push_back(v);
        
        return;
    }

    v.push_back(i);
    
    solve(v , i + 1 , n , k - 1);
    
    v.pop_back();
    
    solve(v , i + 1 , n , k);
    
    return;

}

vector<vector<int> > Solution::combine(int n, int k) {
    result.clear();

    vector<int> v;

    solve(v , 1 , n , k);

    return result;

}

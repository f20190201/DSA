vector<vector<int>>res;

void solve(vector<int> &A, vector<int> &v , int B , int index){

    if(B == 0){
        res.push_back(v);
        return;
    }

    for(int i = index ; i < A.size() ; i++){
        
        if(A[i] > B)
            break;

        v.push_back(A[i]);
        solve(A , v , B - A[i] , i + 1);
        v.pop_back();
    }

    return;

}

vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    res.clear();
    sort(A.begin() , A.end());

    vector<int>v;

    solve(A , v , B , 0);

    set<vector<int>>s;

    for(auto x : res)
        s.insert(x);
    
    res.clear();

    for(auto itr = s.begin() ; itr != s.end() ; ++itr)
        res.push_back(*itr);
    
    return res;
}

void choose(const vector<int>& A, int index, int target, vector<int> current, vector<vector<int>>& ans) {
    if (target == 0) ans.push_back(current);
    
    for (auto i = index; i < A.size(); ++i) {
        if (A[i] > target) break;

        current.push_back(A[i]);
        choose(A, i, target - A[i], current, ans);
        current.pop_back();
    }
}

vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    sort(A.begin(), A.end());
    A.erase(unique(A.begin(), A.end()), A.end());
    
    vector<vector<int>> ans;
    choose(A, 0, B, {}, ans);
    return ans;
}


------------------------------------------------------------------------------------------------------------------------------
  
  
  vector<vector<int>> res;

void combo(vector<int> &A, int B , vector<int> &v , int index){
    
    if(index == A.size() or B <= 0){
        if(B == 0){
            res.push_back(v);
        }
        return;
    }
        v.push_back(A[index]);
        combo(A , B - A[index] , v , index);
        v.pop_back();
        combo(A , B , v , index + 1);

    return;


}

vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    res.clear();
    sort(A.begin() , A.end());
    vector<int>v;

    combo(A , B , v , 0);

    int j = 0;
    set<vector<int>>s;

    for(int i = 0 ; i < res.size() ; i++)
        s.insert(res[i]);

    res.clear();

    for(auto itr = s.begin() ; itr != s.end() ; ++itr)
        res.push_back(*itr);

    return res;

}

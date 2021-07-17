vector<string> maps {"0" , "1" , "abc" , "def" , "ghi" , "jkl" , "mno" , "pqrs" , "tuv" , "wxyz"};
vector<string> result;

void solve(string A , string &v , int index){

    if(index == A.size()){
        
        result.push_back(v);
        return;
    }

    for(int i = 0 ; i < maps[A[index] - '0'].size() ; i++){
        
        v.push_back(maps[A[index] - '0'][i]);
        solve(A , v , index + 1);
        v.pop_back();

    }

    return;
}


vector<string> Solution::letterCombinations(string A) {
    result.clear();

    string v;

    solve(A , v , 0); 

    // cout<<result.size()<<endl;

    return result;
}

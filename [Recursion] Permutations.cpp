vector<vector<int>> result;

void solve(vector<int> &A , int l , int r){

    if(l == r){
        result.push_back(A);
        return;
    }
    
    for(int i = l ; i <= r ; i++){
        
        swap(A[l] ,A[i]);

        solve(A , l + 1 , r);

        swap(A[l] , A[i]);
    }

    return;

}

vector<vector<int> > Solution::permute(vector<int> &A) {
    result.clear();

    vector<int> v = A;

    solve(v , 0 , v.size() - 1);

    return result;

}


---------------------------------------------------------------------------------------------------------
  
  void solve(int n, vector< int > &curr, vector<vector< int >> &res, vector< bool > &vis, vector< int > &a)

{


if(curr.size() == n)
{
    res.push_back(curr);
    return;
}

for(int i = 0; i < n; i++)
{
    if(vis[i] == false)
    {
        vis[i] = true;
        curr.push_back(a[i]);
        solve(n, curr, res, vis, a);
        curr.pop_back();
        vis[i] = false;
    }
}   

}


vector<vector > Solution::permute(vector &A) {


int n = A.size();
vector<int> curr;
vector<vector<int>> res;
vector<bool> vis(n, false);

solve(n, curr, res, vis, A);

return res;

}

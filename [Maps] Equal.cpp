vector<int> Solution::equal(vector<int> &A) {
    int N = A.size();
    map<int , vector<int>>mp;
    vector<vector<int>>v;

    for(int i = 0 ; i < N - 1 ; i++){
        for(int j = i + 1 ; j < N ; j++){
            int sum = A[i] + A[j];
            
            if(mp.count(sum)){
                if(mp[sum][0] != i and mp[sum][1] != j and mp[sum][0] != j and mp[sum][1] != i)
                    v.push_back({mp[sum][0] , mp[sum][1] , i , j});
            }
            
            else
                mp[sum] = {i , j};
        }
    }

    if(!v.size())
        return {};
    // for(auto x : v){
    //     printf("( %d , %d , %d , %d )" ,x[0] , x[1] , x[2] , x[3]);
    // }
    
    sort(v.begin() , v.end());

    return v[0];


}

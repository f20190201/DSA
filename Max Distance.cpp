// Make a vector of pair and sort it in ascending order
// One condition of a[j] >= a[i] is taken care of now
// We just need to find maximum difference of indexes
//

int Solution::maximumGap(const vector<int> &A) {
    if(A.size() == 1)
        return 0;

    vector<pair<int , int>> v;

    for(int i = 0 ; i < A.size() ; i++){
        v.push_back({A[i] , i});
    }
    sort(v.begin() , v.end());

    int max_val = INT_MIN;
    int min_till_now = INT_MAX;

    for(int i = 0 ; i < v.size() ; i++){
        auto p = v[i];
        min_till_now = min(min_till_now , p.second);
        max_val = max(max_val , p.second - min_till_now);

    }
    return max_val;

}

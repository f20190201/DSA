vector<int> Solution::dNums(vector<int> &A, int B) {
    int n = A.size();
    if(B > n)
        return {};

    vector<int> result;
    map<int , int> mp;

    int i = 0 , j = 0;

    while(j < n){
        if(j - i + 1 < B){
            mp[A[j]]++;
        }

        if(j - i + 1 == B){
            mp[A[j]]++;
            result.push_back(mp.size());
            mp[A[i]]--;
            if(!mp[A[i]])
                mp.erase(A[i]);
            i++;
        }
        j++;

    }

    return result;

}

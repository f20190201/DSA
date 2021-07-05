int Solution::solve(vector<int> &A, int B) {
    map<int , int>mp;
    int count = 0;

    for(int i = 0 ; i < A.size() ; i++){
        if(mp.count(B^A[i]))
            count++;

        else
            mp[A[i]]++;

    }
    return count;


}

// Make a general map for storing distinct counts across the three vectors
// Make another map that counts 2nd occurences in a single vector itself
// If there has been no prior occurence in the check map, increment the count in the general map
// Finally traverse the general map and append only the elements that have value >= 2

vector<int> Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    vector<int> result;
    map<int , int>mp;
    map<int , int>check;

    for(int i = 0 ; i < A.size() ; i++){
        if(!check.count(A[i])){
            check[A[i]]++;
            mp[A[i]]++;
        }

    }
    check.clear();

    for(int i = 0 ; i < B.size() ; i++){
        if(!check.count(B[i])){
            check[B[i]]++;

            mp[B[i]]++;
        }
    }
    check.clear();

    for(int i = 0 ; i < C.size() ; i++){
        if(!check.count(C[i])){
            check[C[i]]++;

            mp[C[i]]++;
        }
    }

    for(auto it = mp.begin() ; it != mp.end() ; ++it){
        if(it->second >= 2)
            result.push_back(it->first);
    }

    return result;
}

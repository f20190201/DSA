// We check for (x - B) or (x + B)
// If any of them exists and their value isn't equal to current index, print 1
// Else push element into the map as key with its index as value

int Solution::diffPossible(const vector<int> &A, int B) {
    map<int , int> mp;

    for(int i = 0 ; i < A.size() ; i++){
        
        if(mp.count(A[i] - B) or mp.count(A[i] + B)){
        
            if(mp.count(A[i] - B)){
                if(i != mp.count(A[i] - B))
                    return 1;
            }
        
            else if(mp.count(A[i] + B)){
                if(i != mp.count(A[i] + B))
                    return 1;
            }
        
        }
        
        else
            mp[A[i]] = i;

    }
    return 0;


}

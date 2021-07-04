// Check if (B - element) is available in the map
// If available, push the index of (B - element) and element( index of element is i) into result array and return
// If (B - element) isn't available, push index of element into array only if it isn't present beforehand(so as to store the smallest index value)

vector<int> Solution::twoSum(const vector<int> &A, int B) {
    map<int , int>mp;
    vector<int>result;

    for(int i = 0 ; i < A.size() ; i++){
        if(mp.find(B - A[i]) != mp.end()){
            result.push_back(mp[B - A[i]] + 1);
            result.push_back(i + 1);
            return result;
        }
            
            
        else{
            if(!mp.count(A[i]))
                mp[A[i]] = i;
        }
    }


    return result;
}

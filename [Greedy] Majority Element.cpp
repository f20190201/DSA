int Solution::majorityElement(const vector<int> &A) {
    map<int , int>mp;

    for(int i = 0 ; i < A.size() ; i++)
        mp[A[i]]++;
    
    for(auto it = mp.begin() ; it != mp.end() ; ++it)
        if(it->second > (A.size() / 2))
            return it->first;
        
    return -1;

}


--------------------------------------------------------------------
  
  
  int Solution::majorityElement(const vector<int> &A) {
    int currEl = 0 , count = 0;

    for(auto x: A){
        if(!count)
            currEl = x;

        if(x == currEl)
            count++;
        else
            count--;

    }
    return currEl;
}

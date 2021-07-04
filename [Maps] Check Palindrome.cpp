int Solution::solve(string A) {
    unordered_set<char> s;
    for(int i=0;i<A.length();i++){
        if(s.find(A[i])==s.end()){
            s.insert(A[i]);
        }
        else{
            s.erase(A[i]);
        }
    }
    // cout<<s.size()<<endl;
    if(s.size()<=1){
        return 1;
    }
    return 0;
}


------------------------------------------------------------------
  
  
  int Solution::solve(string A) {
    map<char , int>mp;
    int even = 0 , odd = 0 , N = A.size();

    for(int i = 0 ; i < A.size() ; i++){
        mp[A[i]]++;
    }

    if(N % 2 == 0){
        for(auto it = mp.begin() ; it != mp.end() ; ++it){
            if(it->second % 2 == 0)
                even++;
            else
                odd++;
        }
        if(odd >= 1)
            return 0;
        return 1;
    }

    for(auto it = mp.begin() ; it != mp.end() ; ++it){
            if(it->second % 2 == 0)
                even++;
            else
                odd++;
        }
        if(odd >= 2)
            return 0;
        return 1;
    

}

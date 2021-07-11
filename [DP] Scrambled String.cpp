map<string , int> mp;
bool solve(const string A, const string B){
    
    if(A.compare(B) == 0)
        return 1;
    
    if(A.size() <= 1)
        return 0;
    
    int n = A.size();
    bool flag = 0;

    if(mp.count(A + ' ' + B))
        return mp[A + ' ' + B];

    for(int i = 1 ; i < n ; i++){
        
        // bool cond1 = solve(A.substr(0 , i) , B.substr(0 , i));
        // bool cond2 = solve(A.substr(i , n - i) , B.substr(i , n - i));

        // bool cond3 = solve(A.substr(0 , i) , B.substr(n - i , i));
        // bool cond4 = solve(A.substr(i , n - i) , B.substr(0 , n - i));

        if((solve(A.substr(0 , i) , B.substr(0 , i)) and solve(A.substr(i , n - i) , B.substr(i , n - i))) or (solve(A.substr(0 , i) , B.substr(n - i , i)) and solve(A.substr(i , n - i) , B.substr(0 , n - i)))){
            flag = 1;
            break;
        }

    }

    return mp[A + ' ' + B] = flag;
}


int Solution::isScramble(const string A, const string B) {
    mp.clear();

    if(A.size() != B.size())
        return 0;

    if(!A.size() and !B.size())
        return 1;
    
    return solve(A , B);
}

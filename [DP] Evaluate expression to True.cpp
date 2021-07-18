map<string , long long>mp;

int solve(string A , int i , int j , bool val){
    
    if(mp.count(to_string(i) + ' ' + to_string(j) + to_string(val)))
        return mp[to_string(i) + ' ' + to_string(j) + to_string(val)];

    if(i > j)
        return 0;
    
    if(i == j){
        if(val == 1){
            
            if(A[i] == 'T')
                return 1;
            return 0;
        }

        else if(val == 0){
            
            if(A[i] == 'F')
                return 1;
            
            return 0;

        }

    }

    long long int ans = 0;

    for(int k = i + 1 ; k <= j - 1 ; k += 2){

        long long int lf = solve(A , i , k - 1 , 0);
        long long int lt = solve(A , i , k - 1 , 1);
        long long int rf = solve(A , k + 1 , j , 0);
        long long int rt = solve(A , k + 1 , j , 1);

        if(A[k] == '|'){
            if(val == 1)
                ans = ans%1003 + (lf*rt + lt*rf + lt*rt)%1003;
            else
                ans = ans%1003 + (lf*rf)%1003;
        }

        else if(A[k] == '&'){
            if(val == 1)
                ans = ans%1003 + (lt*rt)%1003;
            else
                ans = ans%1003 + (lf*rf + lf*rt + lt*rf)%1003;
        }

        else if(A[k] == '^'){
            if(val == 1)
                ans = ans%1003 + (lt*rf + lf*rt)%1003;
            else
                ans = ans%1003 + (lf*rf + lt*rt)%1003;
        }
        

    }
    mp[to_string(i) + ' ' + to_string(j) + to_string(val)] = ans;
    return ans;

}

int Solution::cnttrue(string A) {
    mp.clear();

    return solve(A , 0 , A.size() - 1 , 1) % 1003;
}

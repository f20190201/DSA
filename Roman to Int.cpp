// If a current roman digit is lesser than its succeeding digit, it is subtracted from the current number, else, it is added

int Solution::romanToInt(string A) {
    map<char , int>mp;

    mp.insert({'I' , 1});
    mp.insert({'L' , 50});
    mp.insert({'V' , 5});
    mp.insert({'C' , 100});
    mp.insert({'X' , 10});
    mp.insert({'D' , 500});
    mp.insert({'M' , 1000});

    int n = A.size();

    if(n == 1)
        return mp[A[0]];
    
    int num = 0;
    int i;

    for(i = 0 ; i < n - 1 ; i++){
        
        if(mp[A[i]] < mp[A[i + 1]])
            num = num - mp[A[i]];
        
        else
            num = num + mp[A[i]];
    }
    num = num + mp[A[i]];

    return num;


}

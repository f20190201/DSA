string Solution::fractionToDecimal(int A, int B) {
    #define int long long int

    if(!A)
        return "0";
    
    string result = "";

    int num = (int)A;
    int denum = (int)B;

    if(num < 0 ^ denum < 0)   //not doing A*B because it may cause overflow
        result += '-';

    if(denum == 1)
        return to_string(num);


    num = abs(num);
    denum = abs(denum);

    int q = num/denum , r = num % denum;

    result += to_string(q);

    if(!r){
        return result;
    }

    result += '.';

    map<int , int> mp;

    while(r){

        if(mp.count(r)){
            result.insert(mp[r] , "(");
            result += ')';
            return result;
        }

        mp[r] = result.size();

        r *= 10;

        result += ('0' + r/denum);

        r = r % denum;

    }

    return result;
}

// We first store all digits in a vector
// We now take digit one by one and put it in a map after ensuring that it isn't already present
// We make nested loops and check for the products. If they are already present, return 0

int Solution::colorful(int A) {
    int num = A;
    map<int , int>mp;
    vector<int> v;

    while(num){
        v.push_back(num % 10);
        num /= 10;
    }

    for(auto x : v){
        if(mp.count(x))
            return 0;
        else
            mp[x] = 1;
    }

    for(int i = 0 ; i < v.size() ; i++){
        int a = v[i];

        for(int j = i + 1 ; j < v.size() ; j++){
            a *= v[j];
            if(mp.count(a))
                return 0;
            else
                mp[a] = 1;
        }

    }
    return 1;
}

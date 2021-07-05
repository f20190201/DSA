int M;
long long int mod(long long x){
        return((x%M) + M) % M;
}

long long int multiply(long long a , long long b){
    return mod(mod(a) * mod(b));
}

long long power(int x , int y){
    if (!y) return 1;
    if(y == 1)  return mod(x);

    if(y % 2 == 0)
        return power(multiply(x , x) , y /2);
    
    return multiply(x , power(x , y - 1));

}

int Solution::Mod(int x, int n, int d) {
    
    if(!x)
        return 0;
    M = d;

    return power(x , n);

}

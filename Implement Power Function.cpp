// If the power is odd, we multiply the result with one instance of base, thereby making the power even
// Now we multiply base with itself and divide the power by 2

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

    long long result = 1;

    while(y){
        if(y%2 == 1)
            result = multiply(result , x);
        y = y / 2;
        x = multiply(x , x);
    }

    return result;

}


int Solution::pow(int x, int n, int d) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(!x)
        return 0;
    M = d;

    return power(x , n);

}

// We find the highest power of 2 just lesser than N
// Except for the leftmost bits, all other bits till this point appear for N/2 times
// We calculate this and add it to (N - highest power - 1) to account for the leftmost bit for the remaining numbers
// We recursively call for the difference

#define M 1000000007

int Solution::solve(int A) {
    #define int long long int
    if(A == 0)
        return 0;
    
    int count = 0;

    int x = floor(log2(A));
    int prod = (1 << x)%M;

    count += (((prod/2)*(x%M))%M + (A - prod + 1)%M + solve(A - prod)%M);

    return (count%M);
}

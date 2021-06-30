// Pairwise - we can find the number of zeroes bitwise and number of ones bitwise
// We multiply both of them to get a pairwise value and then double it to account for the reverse pairings

#define M 1000000007

int Solution::cntBits(vector<int> &A) {
    #define int long long int
    int ans = 0;
    int N = A.size();

    for(int i = 0 ; i < 32 ; i++){
        int ones = 0;
        for(int j = 0 ; j < A.size() ; j++){
            ones += (A[j] & 1)%M;
            A[j] >>= 1;
        }
        ans += (2*(ones%M)*(N - ones)%M);
    }
    return (ans%M);

}

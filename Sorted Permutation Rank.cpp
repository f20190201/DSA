// We find the number of letters smaller than the first letter(rank).
// The result contibuted by this letter is (number of smaller letters)*(places left!)
// We then recurse for substring excluding the first letter and keep adding the contribution to result variable

int factorial(int N){
    if(N <= 1)
        return 1;
    
    long long int ret = N%1000003 * factorial(N-1)%1000003;
    return ret;
}

int Solution::findRank(string A) {
    int N = A.size();
    if(N == 1)
        return N;
    long long int result = 0;
    int rank = 0;

    for(int i=0;i<A.size();i++){
        if(A[i] < A[0])
            rank++;
    }

    result += (factorial(N-1)*rank)%1000003;

    result += findRank(A.substr(1))%1000003;

    

return (result)%1000003;
}

// For storing 2 values in one variable, we use mod.
// If N is the length of the array, a and b are two numbers to be stored,
// then x = a + b*N
// x stores both a and b, since, x%N is a and x/N is b

void Solution::arrange(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int N = A.size();
    
    for(int i = 0 ; i < N ; i++){
        A[i] = A[i] + (N*(A[A[i]]%N));
    }

    for(int i = 0 ; i < N ; i++)
        A[i] = A[i]/N;

    return;


}

int Solution::removeElement(vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int index = 0 , n = A.size();

    for(int i = 0 ; i < n ; i++){
        if(A[i] == B)
            continue;
        A[index] = A[i];
        index++;
    }

    return index;

}

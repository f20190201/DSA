int index(vector<int> &A, int B){
    int N = A.size();
    int low = 0;
    int high = N - 1;
    int mid = low + (high - low) / 2;
    int res = 0;

    while(low <= high){
        mid = low + (high - low) / 2;
        
        if(A[mid] >= B){
            res = mid;
            high = mid - 1;
        }

        else if(A[mid] < B)
            low = mid + 1;

    }
    return res;

}


int Solution::searchInsert(vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(B < A[0])
        return 0;
    
    if(B > A[A.size() - 1])
        return A.size();

    return index(A , B); //This returns the index of the element if found or the next greater elemnt if the element not found

}

void Solution::merge(vector<int> &A, vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int m = A.size() - 1, n = 0;

    while(m >= 0 and n < B.size()){
        if(A[m] > B[n])
            swap(A[m] , B[n]);

        m--;
        n++;
    }
    sort(A.begin() , A.end());
    sort(B.begin() , B.end());

    for(int i = 0 ; i < B.size() ; i++)
        A.push_back(B[i]);

    return;
    
}

----------------------------------------
  
  
  void Solution::merge(vector<int> &A, vector<int> &B)
{
    
    // O(1) space
    // If all elements of B are placed in array
    // then elements of A are already in place
    
    int i = A.size() - 1; // i pointing to last index of A
    int j = B.size() - 1; // j pointing to last index of B
    
    int lastPos = A.size() + B.size() - 1; // lastPos pointing to last index of merged array A and B
    
    A.resize(A.size() + B.size());
    
    while(j >= 0)
    {
        if(i >= 0 and A[i] > B[j])
            A[lastPos--] = A[i--];
        else
            A[lastPos--] = B[j--];
    }
    
}

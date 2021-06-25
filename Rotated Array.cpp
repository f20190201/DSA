// If number of times a sorted array is rotated is x, then minimum element is A[x]

int Solution::findMin(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int times_rotated = 0;
    
    for(int i = 0 ; i < A.size() - 1 ; i++){
        if(A[i] > A[i+1]){
            times_rotated = i+1;
        }
    }
    return A[times_rotated % A.size()];



}


---------------------------------------------------------------------------
  
  
  
 class Solution {
    public:
        int findMin(const vector<int> &A) {
            int low = 0, high = (int)A.size() - 1;
            int len = A.size();
            while (low <= high) {
                if (A[low] <= A[high]) return A[low]; // Case 1
                int mid = (low + high) / 2;
                int next = (mid + 1) % len, prev = (mid + len - 1) % len;
                if (A[mid] <= A[next] && A[mid] <= A[prev]) // Case 2
                    return A[mid];
                else if (A[mid] <= A[high]) high = mid - 1; // Case 3
                else if (A[mid] >= A[low]) low = mid + 1; // Case 4
            }
            return -1;
        }
};

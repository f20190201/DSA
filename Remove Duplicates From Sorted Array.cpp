int Solution::removeDuplicates(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int start = 0 , end = 0 , N = A.size();


    for(int i = 0 ; i < N - 1 ; i++){
        end = i;
        start = end;

        while(A[i] == A[i + 1] and (i < A.size() - 1)){
            i++;
            end = i;
        }

        if(start != end){
            A.erase(A.begin() + start , A.begin() + end);
            end = start;
            i = start;
            N = A.size();
        }
    }
    return A.size();

}


-------------------------------------------------
  
  
  class Solution {
	public:
		int removeDuplicates(vector<int> &A) {
			int count = 0, n = A.size();
			for (int i = 0; i < n; i++) { 
				if (i < n - 1 && A[i] == A[i+1]) continue;
				else {
					A[count] = A[i];
					count++;
				}
			}
			return count;
		}  
};

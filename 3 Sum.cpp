// Take an outer loop and then two pointers for sum of other 2 numbers

int Solution::threeSumClosest(vector<int> &A, int B) {
    #define int long long int
    sort(A.begin() , A.end());
    int result = INT_MAX , ans;
    
    for(int i = 0 ; i < A.size() - 1 ; i++){
        int l = i + 1;
        int r = A.size() - 1;

        while(l < r){
            int sum = A[i] + A[l] + A[r];
            // sum - B should be minimum
            if(abs(sum - B) < result){
                result = abs(sum - B);
                ans = sum;
            }

            if(sum > B)
                r--;
            else
                l++;
        }

    }


    return ans;


}

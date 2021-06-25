int Solution::solve(vector<int> &a, int k) {
    int l=0;
    int r=a.size()-1;
    int ans=0;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(a[mid]<=k)
        {
            ans=mid+1;
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }
    return ans;
}

------------------------------------------------------------------------------------
  
  
  int last(vector<int> &A, int B){
    int N = A.size();
    int high = A.size() - 1;
    int low = 0;
    int mid = low + (high - low) / 2;
    int result = -1;

    while(low <= high){
        mid = low + (high - low) / 2;

        if(A[mid] == B){
            result = mid;
            if(mid == N-1){
                result = mid;
                break;
            }
            if(A[mid+1] == B)
                low = mid + 1;
            
            if(A[mid + 1] > B)
                // result = mid;
                break;
        }
        else if(A[mid] > B){
            result = mid;
            high = mid - 1;
        }
        else if(A[mid] < B){
            low = mid + 1;
        }

    }

    return result;
}

int Solution::solve(vector<int> &A, int B) {
    if(B < A[0])
        return 0;
    if(B >= A[A.size() - 1])
        return A.size();

    int index = last(A , B);

    if(A[index] == B)
        return index + 1;
    
    return index;



}

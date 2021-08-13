// https://binarysearch.com/problems/Kth-Smallest-Element

int partition(vector<int>& A , int start , int end){
    int pivot = A[start] , j = end;
    int i = start + 1;

    while(i <= j){
        if(A[i] >= pivot)
            swap(A[i] , A[j--]);
        
        else
            i++;
    }

    swap(A[start] , A[j]);

    return j;
}

int solve(vector<int>& nums, int k) {
    int low = 0 , high = nums.size() - 1;

    while(low < high){
        int mid = partition(nums , low , high);

        if(mid == k)
            return nums[mid];
        
        else if(mid < k)
            low = mid + 1;
        
        else
            high = mid - 1;
    }

    return nums[k];
}

// We first find the min_element of the array using binary search
// The subarrays from start to min_element - 1 and min_element to end are sorted
// We run binary search for the two subarrays and check for the target element

int Bsearch(const vector<int> &A , int low1 , int high1 , int B){
    int low = low1 , high = high1;
    int mid = low + (high - low) / 2;

    while(low <= high){
        mid = low + (high - low) / 2;

        if(A[mid] == B)
            return mid;
        else if(A[mid] < B)
            low = mid + 1;
        else
            high = mid - 1;

    }
    return -1;

}

int Solution::search(const vector<int> &A, int B) {
    int res = -1 , low = 0 , high = A.size() - 1;
    int mid = low + (high - low) / 2;
    int min_ele;


    while(low <= high){
        
        if(A[low] < A[high]){
            min_ele = low;
            break;
        }

        mid = low + (high - low) / 2;
        int next = (mid + 1)%(A.size()) , prev = (mid + A.size() - 1)%(A.size());

        if(A[mid] <= A[next] and A[mid] <= A[prev]){
            min_ele = mid;
            break;
        }
        
        else if(A[mid] <= A[high])  high = mid - 1;
        else low = mid + 1;

    }
    
    int left = Bsearch(A , 0 , min_ele - 1 , B);
    int right = Bsearch(A , min_ele , A.size() - 1 , B);

    if(left != -1)
        return left;
    if(right != -1)
        return right;
    return -1;


}


----------------------------------------------------------------


int Solution::search(const vector<int> &A, int B) {
    int n = A.size();
    int low = 0, high = n-1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(A[mid] == B) return mid;
        else if(A[0]<=A[mid]){//i.e. left part is sorted
            if(A[0]<=B && B < A[mid]) high = mid-1;//B lies on left part
            else low = mid+1;
        }else{//right part is sorted
            if(A[mid] < B && B<=A[n-1]) low = mid+1;//B lies on right part
            else high = mid-1;
        }
    }
    return -1;
}

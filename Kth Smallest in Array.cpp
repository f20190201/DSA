// Use binary search between the ranges max and min
// If number of elements lesser than equal to mid is less than B, increase mid
// If number of elements lesser than mid is lesser than mid and its sum with equal elements is more than B, then mid is the answer
// If number of elements lesser is more than mid, then decrease mid

int Solution::kthsmallest(const vector<int> &A, int B) {
    int low = *min_element(A.begin() , A.end());
    int high = *max_element(A.begin() , A.end());

    while(low <= high){
        int mid = low + (high - low) / 2;

        int less = 0 , equal = 0;

        for(int i = 0 ; i < A.size() ; i++){
            if(A[i] == mid)
                equal++;
            else if(A[i] < mid)
                less++;
        }

        if(less < B and (less+equal) >= B)
            return mid;
        else if(less >= B)
            high = mid - 1;
        else if((less + equal) < B)
            low = mid + 1;

    }

    
}

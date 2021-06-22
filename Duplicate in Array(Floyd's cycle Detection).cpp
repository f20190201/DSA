// Convert the array into a LL
// Make a fast and slow pointer and compare the values

int Solution::repeatedNumber(const vector<int> &A) {
    if(A.size() <= 1)
        return -1;

    int slow = A[0];
    int fast = A[A[0]];

    while(fast != slow){
        slow = A[slow];
        fast = A[A[fast]];
    }
    slow = 0;
    while(fast != slow){
        slow = A[slow];
        fast = A[fast];
    }

    if(slow == fast)
        return slow;
    return -1;
    
}

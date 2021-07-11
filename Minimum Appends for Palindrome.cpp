// Min appends is the min number of waste characters at the start
// temp variable stores the lowest value for which the string ivolving the elast character can be a palindrome
// We are basically finding the length of longest substring involving the last character of the original string

int Solution::solve(string A) {
    int temp = 0 , start = 0 , end = A.size() - 1;

    while(start <= end){
        if(A[start] == A[end]){
            start++;
            end--;
            continue;
        }
        
        end = A.size() - 1;
        start = temp + 1;
        temp = start;
    }

    return temp;
}

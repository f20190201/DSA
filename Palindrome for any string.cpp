int Solution::isPalindrome(string A) {
    int i = 0 , j = (int)(A.size() - 1);

    while(i < j){
        while(i < j and !isalnum(A[i])) i++;
        while(i < j and !isalnum(A[j])) j--;

        if(tolower(A[i]) != tolower(A[j]))
            return 0;
        i++;
        j--;
    }
    return 1;
    
}

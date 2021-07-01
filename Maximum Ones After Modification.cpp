// Maximum number of consecutive ones after modification is the maximum length of 0s

int Solution::solve(vector<int> &A, int B) {
    int count = 0 , start = 0 , end = 0 , n = A.size() , result = 0;
    
    for(int i = 0 ; i < n ; i++){
        if(!A[i])
            count++;
        
        while(count > B){
            if(A[start] == 0)
                count--;
            start++;
        }
        result = max(result , i - start + 1);

    }
    return result;
}

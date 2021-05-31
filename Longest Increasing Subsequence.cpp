

int longestSubequence(int n , int arr[]){
    int result[n+1];
    result[0] = INT_MIN;
    
    for(int i = 1 ; i < n ; i++)
        result[i] = INT_MAX;
    
    for(int i = 0 ; i < n ; i++){
        int index = (upper_bound(result , result + n + 1 , arr[i]) - result);
        
        if(arr[i] > result[index - 1] && arr[i] < dp[index])
            result[index] = arr[i];
    }
    
    int answer = 0;
    
    for(int i = n - 1 ; i >= 0 ; i--){
        if(result[i] != INT_MAX)
            answer = i;
            break;
    }
}

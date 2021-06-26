int wood_obtained(vector<int> &A , long long int mid){
    long long int sum = 0;

    for(int i = 0 ; i < A.size() ; i++)
        sum += max((long long int)0 , A[i] - mid);

    return sum;
}


int Solution::solve(vector<int> &A, int B) {
    sort(A.begin() , A.end());
    int res = -1;

    long long int high = A[A.size() - 1];

    long long int low = 0 , mid;

    mid = low + (high - low) / 2;

    while(low <= high){
        mid = low + (high - low) / 2;

        if(wood_obtained(A , mid) >= B){
            res = mid;
            low = mid + 1;
        }
        
        else
            high = mid - 1;
    }
 
    return res;

}








int wood_obtained(vector<int> &A , long long int mid){
    long long int sum = 0;

    for(int i = 0 ; i < A.size() ; i++){
        if((A[i] - mid) > 0)
            sum += (A[i] - mid);
    }

    return sum;
}


---------------------------------------------------------------------------------

  
int Solution::solve(vector<int> &A, int B) {
    
    long long int high = INT_MIN;

    for(int i = 0 ; i < A.size() ; i++){
        if(A[i] > high)
            high = A[i];
    }
        
    
    int res = -1;

    long long int low = 0 , mid;

    mid = low + (high - low) / 2;

    while(low <= high){
        mid = low + (high - low) / 2;

        if(wood_obtained(A , mid) >= B){
            res = mid;
            low = mid + 1;
        }
        
        else
            high = mid - 1;
    }
 
    return res;

}

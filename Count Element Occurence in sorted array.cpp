int first(const vector<int> &A , int B){
    int N = A.size();
    
    int high = N-1;
    int low = 0;
    int mid = low +(high - low)/2;
    int res = -1;

    while(high >= low){
        mid = low +(high - low)/2;
        
        if(A[mid] > B)
            high = mid - 1;
        
        else if(A[mid] < B)
            low = mid + 1;
        
        else{
            res = mid;
            high = mid - 1;
        }

    }
    return res;

}

int last(const vector<int> &A , int B){
    int N = A.size();
    
    int high = N-1;
    int low = 0;
    int mid = low +(high - low)/2;
    int res = -1;

    while(high >= low){
        mid = low +(high - low)/2;
        
        if(A[mid] > B)
            high = mid - 1;
        
        else if(A[mid] < B)
            low = mid + 1;
        
        else{
            res = mid;
            low = mid + 1;
        }

    }
    return res;

}

int Solution::findCount(const vector<int> &A, int B) {
    if(A.size() == 1){
        if(B == A[0])
            return 1;
        return 0;
    }

    int lower = first(A , B);
    int higher = last(A , B);

    if(lower == -1 and higher == -1)
        return 0;
    
    return (higher - lower + 1);

}

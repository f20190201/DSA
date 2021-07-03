

------------------------------------------------------------------------

Two Pointer Approach

int Solution::trap(const vector<int> &A) {
    int l = 0 , h = A.size() - 1 , leftMax = INT_MIN , rightMax = INT_MIN;
    int result = 0;

    while(l <= h){
        
        if(leftMax < rightMax){
            
            if(A[l] > leftMax)
                leftMax = A[l];

            else
                result += (leftMax - A[l]);

            l++;
        }
        else{
            
            if(A[h] > rightMax)
                rightMax = A[h];

            else
                result += (rightMax - A[h]);
            
            h--;
        }

    }

    return result;
}


------------------------------------------------------------------------

Using LeftMax and RightMax array

int Solution::trap(const vector<int> &A) {
    vector<int> leftMax(A.size() , 0);
    vector<int> rightMax(A.size() , 0);
    int key = INT_MIN;

    for(int i = 0 ; i < A.size() ; i++){
        key = max(key , A[i]);
        leftMax[i] = key;
    }
    key = INT_MIN;

    for(int i = A.size() - 1 ; i >= 0 ; i--){
        key = max(key , A[i]);
        rightMax[i] = key;
    }

    int result = 0;

    for(int i = 1 ; i < A.size() - 1 ; i++){
        int height = min(leftMax[i] , rightMax[i]) - A[i];
        result += height;
    }
    return result;
}

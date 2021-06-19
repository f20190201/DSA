// Need to find if an element exists that is greater than all elements on its left and smaller than all elements on its right
// We create a leftmax and righmin array
// If the number lies between the corresponding values in leftmax and rightmin, that particular number satisfies the requirement

int Solution::perfectPeak(vector<int> &A) {
    vector<int>leftMax(A.size());
    vector<int>rightMin(A.size());

    int temp = A[0];
    leftMax[0] = -1;
    for(int i = 1 ; i < A.size() ; i++){
        if(A[i-1] > temp)
            temp = A[i-1];

        leftMax[i] = temp;
    }
    temp = A[A.size() - 1];
    rightMin[A.size() - 1] = -1;

    for(int i = A.size() - 2 ; i >= 0 ; i--){
        if(A[i+1] < temp)
            temp = A[i+1];
        rightMin[i] = temp;
    }
    // for(auto x: leftMax)
    //     cout<<x<<" ";
    //     cout<<endl;
    // for(auto x: rightMin)
    //     cout<<x<<" ";
    //     cout<<endl;

    for(int i = 1 ; i < A.size() - 1 ; i++){
        if((A[i] > leftMax[i]) and (A[i] < rightMin[i]))
            return 1;
    }
    return 0;
}

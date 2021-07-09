int merge(vector<int> &A , int start , int mid , int end){
    int inversions = 0;
    int n1 = mid - start + 1;
    int n2 = end - mid;
    int a[n1];
    int b[n2];

    for(int i = 0 ; i < n1 ; i++)
        a[i] = A[start + i];

    for(int i = 0 ; i < n2 ; i++)
        b[i] = A[mid + i + 1];
    
    int i = 0 , j = 0 , k = start;

    while(i < n1 and j < n2){
        if(a[i] <= b[j]){
            A[k] = a[i];
            k++;    i++;
        }
        else{
            A[k] = b[j];
            inversions += (n1 - i);
            j++;    k++;

        }

    }
    while(i < n1){
        A[k] = a[i];
        k++;    i++;
    }

    while(j < n2){
        A[k] = b[j];
        k++;    j++;
    }
    return inversions;
}

int mergeSort(vector<int> &A , int start , int end){
    int inversions = 0;

    if(start < end){
        int mid = (end + start) / 2;

        inversions += mergeSort(A , start , mid);
        inversions += mergeSort(A , mid + 1 , end);
        inversions += merge(A , start , mid , end);

    }
    
    return inversions;
}

int Solution::countInversions(vector<int> &A) {
    
    return mergeSort(A , 0 , A.size() - 1);
}

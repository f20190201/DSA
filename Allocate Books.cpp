// We use binary search to first assume the answer.
// We then use the assumed answer with a function isValid() which checks if that can be valid.

//isValid() counts the number of students required with the assumed maximum pages. If the number of students required > number of students given, return 0

int isValid(vector<int> &A , int B , int k){
    //no. of students = n
    //max pages = k
    int students = 0;

    for(int i = 0 ; i < A.size() ; i++){
        int filled = 0;

        while((filled + A[i]) <= k and i < A.size()){
            filled += A[i];
            i++;
        }
        students++;
        i--;
    }

    if(students <= B)
        return 1;
    return 0;
}



int Solution::books(vector<int> &A, int B) {
    int n = A.size();

    if(B > n)
        return -1;
    
    int start = *max_element(A.begin() , A.end());
    int end = 0;
    
    for(auto x:A)
        end += x;


    if(B == n)
        return start;
    
    int ans = -1;

    while(start <= end){
        int mid = start + (end - start) / 2;

        if(isValid(A , B , mid)){
            ans = mid;
            end = mid - 1;
        }

        else
            start = mid + 1;
    }
    
    return ans;

}

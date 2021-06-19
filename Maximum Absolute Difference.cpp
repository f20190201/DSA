// |arr[i] - arr[j]| + |i - j| can be opened up under the 4 conditions
// Of these, two conditions are negative inverses of the remaining two
// The two conditions left are - 
// (i - arr[i]) - (j - arr[j])    and    (i + arr[i]) - (j + arr[j]) 
// (i - arr[i]) and (i + arr[i]) are the expressions for which we need to find maximum values


int Solution::maxArr(vector<int> &A) {
    vector<int> plus;
    vector<int> minus;

    for(int i = 0 ; i < A.size() ; i++){
        plus.push_back(i + A[i]);
        minus.push_back(i - A[i]);
    }

    sort(plus.begin() , plus.end());
    sort(minus.begin() , minus.end());

    return max(abs(plus[0] - plus[plus.size() - 1]) , abs(minus[0] - minus[minus.size() - 1]));
}

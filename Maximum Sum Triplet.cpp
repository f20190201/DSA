// In the iteration process, we take the current element to be the middle element
// The left element is found by binary search in a set that conatins all the elements in the left subarray
// The right element is found by right maximum subarray
// It is also checked if the right element is greater than our current element, if not, the triad is discarded from further calculations

int Solution::solve(vector<int> &A) {
//int temp_sum = 0;
int max_sum = INT_MIN;
int right = INT_MIN;
vector<int> rightMax(A.size() , 0);
set<int> s;
    for(int i = A.size() - 1 ; i >= 0 ; i--){
        if(A[i] >= right){
            rightMax[i] = (A[i]);
            right = A[i];
            }
        else
            rightMax[i] = right;
    }
        s.insert(A[0]);
    //set<int> :: iterator itr1 , itr2;
    for(int j = 1 ; j < A.size() - 1 ; j++){
        
        s.insert(A[j]);
        
        int valueright = rightMax[j+1];

        if(valueright > A[j]){
            auto itr = s.find(A[j]);
            if(itr!=s.begin()) {
            max_sum = max(max_sum, (A[j]+(*(--itr))+valueright));
            }
            
            //temp_sum = *it + A[j] + valueright;
            //max_sum = max(max_sum , temp_sum);
        }
    }

    return max_sum;


}

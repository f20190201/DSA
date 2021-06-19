vector<int> Solution::maxset(vector<int> &A) {
    vector<int> result;
    long long max_sum = 0;
    vector<int> temp_ans;
    long long total = 0;

    for(int i = 0 ; i < A.size() ; i++){
      
    // Consider the element only if it is non-negative
      
        if(A[i] >= 0){
          // total variable stores the temporary sum and temp_ans stores the temporary result vector
            total += A[i];
            temp_ans.push_back(A[i]);
// When temporary sum > max_sum till now, we update max_sum and also the result vector
            if(total > max_sum){
                max_sum = total;
                result = temp_ans;
            }
          // Returning the vector with largest size when temporary sum == max_sum
            else if(total == max_sum){
                if(temp_ans.size() > result.size())
                    result = temp_ans;
            }

        }
// Clear the total variable and temp_ans vector to make way for a new subArray
        else if(A[i] < 0){
            if(temp_ans.size() != 0)
                temp_ans.clear();
            total = 0;
        }
    }
    return result;
}

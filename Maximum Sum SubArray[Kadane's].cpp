

int Solution::maxSubArray(const vector<int> &A) {
    int max_sum = INT_MIN;
    int temp_sum = 0;

    for(auto x: A){
        temp_sum += x;
        if(temp_sum > max_sum)
            max_sum = temp_sum;
        if(temp_sum < 0)
            temp_sum = 0;
    }
    return max_sum;

}

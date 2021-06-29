// If we sum value of each bit of all the numbers, the repeating numbers would be multiple of 3
// If we mod each bit sum by 3, we get the required set bit of our required number.
// Now with the help of set bits, we convert binary to decimal and return the value

int Solution::singleNumber(const vector<int> &A) {
    int ans = 0;
    
    for(int i = 0 ; i < 32 ; i++){
        int sum = 0;
        for(int j = 0 ; j < A.size() ; j++){
            sum += ((A[j] >> i) & 1);
        }
        ans += (sum % 3)*(pow(2 , i));
    }

    

    return ans;

}

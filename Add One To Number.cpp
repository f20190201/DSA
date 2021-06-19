// The given vector can have non significant 0s

vector<int> Solution::plusOne(vector<int> &A) {
    vector<int>result;
    int jackpot = 0;
  
  // Iteration to find the first significant digit
    for(int i = 0 ; i < A.size() ; i++){
        if(A[i] != 0){
            jackpot = i;
            break;
        }
        
    }
  //Making a new vector with only significant digits
    vector<int> vect2;
    vect2.assign(A.begin() + jackpot, A.end());

    reverse(vect2.begin() , vect2.end());

    int carry = 0;

    result.push_back((vect2[0] + 1)%10);
    carry = (vect2[0] + 1)/10;

    for(int i = 1 ; i < vect2.size() ; i++){
        long long sum = vect2[i] + carry;
        result.push_back(sum%10);
        carry = sum/10;
    }
    while(carry){
        if(carry != 0){
            result.push_back(carry%10);
        }
        carry = carry/10;
    }
    reverse(result.begin() , result.end());

    return result;

}


----------------------------------------------------------------------
  
  
  
  class Solution {
    public:
        vector<int> plusOne(vector<int> &digits) {
            reverse(digits.begin(), digits.end());
            vector<int> ans;
            int carry = 1;
            for (int i = 0; i < digits.size(); i++) {
                int sum = digits[i] + carry;
                ans.push_back(sum%10);
                carry = sum / 10;
            }
            while (carry) {
                ans.push_back(carry%10);
                carry /= 10;
            }
            while (ans[ans.size() - 1] == 0 && ans.size() > 1) {
                ans.pop_back();
            }
            reverse(ans.begin(), ans.end());
            reverse(digits.begin(), digits.end());
            return ans;
        }
};

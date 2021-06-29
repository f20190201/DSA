string Solution::addBinary(string A, string B) {
    int carry = 0;
    int a = A.size() - 1;
    int b = B.size() - 1;
    string ans = "";

    while(a >= 0 and b >= 0){
        int a1 = A[a] - '0';
        int b1 = B[b] - '0';
        
        if(carry == 0){
            if(a1 == 0 and b1 == 0)
                ans += "0";
            else if(a1 != b1)
                ans += "1";
            else{
                ans += "0";
                carry = 1;
            }
        }

        else{
            if(a1 == 0 and b1 == 0){
                ans += "1";
                carry = 0;
            }
            else if(a1 != b1){
                ans += "0";
                carry = 1;
            }
            else{
                ans += "1";
                carry = 1;
            }

        }
        a--;
        b--;
    }

    while(a >= 0){
        int a1 = A[a] - '0';

        if(!carry){
            if(a1 == 1)
                ans += "1";
            else
                ans += "0";
        }
        else{
            if(a1 == 1){
                ans += "0";
                carry = 1;
            }
            else{
                ans += "1";
                carry = 0;
            }
        
        }
        a--;

    }

    while(b >= 0){
        int a1 = B[b] - '0';

        if(!carry){
            if(a1 == 1)
                ans += "1";
            else
                ans += "0";
        }
        else{
            if(a1 == 1){
                ans += "0";
                carry = 1;
            }
            else{
                ans += "1";
                carry = 0;
            }
        }
        b--;

    }
    if(carry)
        ans += "1";
    
    reverse(ans.begin() , ans.end());

    return ans;

}

--------------------------------------------------------

class Solution {
public:
    string addBinary(string a, string b) {
           string ans = "";
    int ansLen = 0, carry = 0, sum;
    int i = (int)a.length() - 1, j = (int)b.length() - 1;
    while (i >= 0 || j >= 0 || carry) {
        sum = carry;
        if (i >= 0) sum += (a[i] - '0');
        if (j >= 0) sum += (b[j] - '0');
        ans.push_back((char)('0' + sum % 2));
        carry = sum / 2;
        i--; 
        j--;
    }
    reverse(ans.begin(), ans.end());
    return ans;
    }
};

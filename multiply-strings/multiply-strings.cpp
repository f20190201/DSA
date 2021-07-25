class Solution {
public:
    string digitMultiply(string num , char s){
        int carry = 0;
        string res = "";
        
        for(int i = num.size() - 1 ; i >= 0 ; i--){
            int product = ((num[i] - 48) * (s - 48) + carry);
            
            res = to_string(product % 10) + res;
            
            carry = product / 10;
        }
        
        if(carry){
            
            res = to_string(carry % 10) + res;
            carry = carry / 10;
            
        }
        
        return res;
    }
    
    string add(string num1 , string num2){
        string res = "";
        
        int i = num1.size() - 1 , j = num2.size() - 1 , carry = 0;
        
        while(i >= 0 || j >= 0 || carry > 0){
            int sum = carry;
            
            if(i >= 0){
                sum += (num1[i] - 48);
                i--;
            }
            
            if(j >= 0){
                sum += (num2[j] - 48);
                j--;
            }
            
            res = to_string(sum % 10) + res;
            carry = sum / 10;
        }
        return res;
    }
    
    string multiply(string num1, string num2) {
        string res = "0";
        int n = num1.size();
        
        for(int i = n - 1 ; i >= 0 ; i--){
            string temp = digitMultiply(num2 , num1[i]);
            
            int t = n - 1 - i;
            
            while(t--)
                temp += '0';
            
            res = add(res , temp);
        }
        
        int k = 0;
        
        while(res[k] == '0')
            k++;
        if(k == res.size())
            return "0";
        
        return res.substr(k);
    }
};
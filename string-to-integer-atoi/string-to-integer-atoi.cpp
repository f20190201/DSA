class Solution {
public:
    int myAtoi(string s) {
        stringstream ss(s);
        string word , numstr;
        
        while(ss >> word){
            numstr = word;
            break;
        }
        
        if(!numstr.size())
            return 0;
        
        int sign;
        long long num = 0;
        
        sign = (numstr[0] == '-') ? (-1) : (1);
        
        if(numstr[0] == '-' or numstr[0] == '+')
            numstr = numstr.substr(1);
        
        int i = 0;
        
        while(i < numstr.size() and (numstr[i] >= '0' and numstr[i] <= '9')){
            num = num * 10 + (numstr[i] - '0');
            
            if(num >= INT_MAX and sign == 1){
                return INT_MAX;
            }
            
            if(num - 1 >= INT_MAX and sign == -1)
                return INT_MIN;
            
            i++;
        }
        
        return sign*num;
    }   
};
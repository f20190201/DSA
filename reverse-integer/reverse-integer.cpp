#include<bits/stdc++.h>
class Solution {
public:
    
    int reverse(int x) {
        if(!x)
            return x;
        long long int low = (pow(2 , 31));
        long long int high = pow(2 , 31) - 1;
        
        if(x > 0){
            string value = to_string(x);
            ::reverse(value.begin() , value.end());
            if(stoll(value) < high)
                return stoll(value);
            return 0;
        }
        
        if(x < 0){
            int newx = abs(x);
            string value = to_string(newx);
            ::reverse(value.begin() , value.end());
            if(stoll(value) < low)
                return (stoll(value))*(-1);
            return 0;
        }
        
        
        return 0;
        
    }
};



-----------------------------------------------------------------------
    
    class Solution {
public:
    int reverse(int x) {
        
        if(x>INT_MAX || x<INT_MIN) return 0;
        
        int b=0;
        int a=abs(x);
        while(a>0)
        {
            if(b > INT_MAX/10) 
                return 0;
            b=b*10 + a%10;
            a=a/10;
        }
        
        if(x<0)
        {
            return b*(-1);
        }
        return b;
    }
};


---------------------------------------------------------------------
    
    
    class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
            if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
            rev = rev * 10 + pop;
        }
        return rev;
    }
};

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
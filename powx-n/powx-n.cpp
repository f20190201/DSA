class Solution {
public:
    double myPow(double x, int n1) {
        double res = 1;
        
        int sign = n1 > 0;
        
        long long n = abs(n1);
        
        while(n){
            
            if(n % 2){
                res = res * x;
                n--;
            }
            
            x = x * x;
            n = n / 2;
        }
        
        
        if(!sign)
            res = 1 / res;
        
        return res;
    }
};
class Solution {
public:
    double myPow(double x, int n) {
        double res = 1;
        
        long long y = n;
        
        int sign = (y >= 0) ? 1 : -1;
        
        y = abs(y);
        
        while(y){
            
            if(y % 2 != 0){
                res = res * x;
                y--;
            }
            
            y = y / 2;
            x = x * x;
            
        }
        
        if(sign == -1)
            res = 1 / res;
        
        return res;
    }
};
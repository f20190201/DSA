class Solution {
public:
    int rotatedDigits(int n) {
        int t[n + 1] , count = 0;
        
        memset(t , 0 , sizeof(t));
        
        // flags - 0 for invalid , 1 for valid but same , 2 for valid and different
        
        for(int i = 0 ; i <= n ; i++){
            
            if(i < 10){
                
                if(i == 0 or i == 1 or i == 8)
                    t[i] = 1;
                
                else if(i == 2 or i == 5 or i == 6 or i == 9){
                    t[i] = 2;
                    count++;
                }
                
                
                continue;
            }
            
            int a = t[i / 10] , b = t[i % 10];
            
            if(a == 1 and b == 1)
                t[i] = 1;
            
            else if(a >= 1 and b >= 1){
                t[i] = 2;
                count++;
            }
            
        }
        return count;
    }
};
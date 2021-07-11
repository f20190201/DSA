class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>result(n + 1);
        
        for(int i = 1 ; i <= n ; i++){
            
            if(floor(log2(i)) == ceil(log2(i))){
            
                result[i] = 1;
                
                continue;
            }
            
            int nearest_pow = pow(2 , floor(log2(i)));
            
            result[i] = 1 + result[i - nearest_pow];
        }
        
        return result;   
    }
};
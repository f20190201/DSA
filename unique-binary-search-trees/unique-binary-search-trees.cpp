class Solution {
public:
    
    unsigned long long binomialCoeff(int n , int k){
        unsigned long long res = 1;
        
        for(int i = 0 ; i < k ; i++){
            res = res * (n - i);
            res = res / (i + 1);
        }
        
        return res;
    }
    
    int numTrees(int n) {
        unsigned long long ans = 1;
        
        ans = binomialCoeff(2 * n , n);
        
        return ans/(n + 1);
    }
};
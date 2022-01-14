// Catalan Numbers method (2nCn)/(n + 1)
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

//O(n^2) method
// Result can be obtained by summing of all the sub-results which are obtained by keeping each value from 1 to n as root

class Solution {
public:
    int numTrees(int n) {
        
        int dp[n + 1];
        memset(dp , 0 , sizeof(dp));
        
        dp[0] = 1;
        dp[1] = 1;
        
        for(int i = 2 ; i <= n ; i++){  //keeping each value from 2 to n as root
            
            for(int j = 1 ; j <= i ; j++)   //for each root value i, keeping all the values from 1 to i as root
                dp[i] += dp[j - 1] * dp[i - j];
        }
        
        return dp[n];
    }
};

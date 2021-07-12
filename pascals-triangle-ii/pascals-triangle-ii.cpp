class Solution {
public:
    vector<int> getRow(int n) {
        if(!n)
            return {1};
        
        vector<int> result;
        
        result.push_back(1);
        
        for(int i = 1 ; i <= n ; i++){
            
            long long int temp = 1ll * result[i - 1] * (n - i + 1) / i;
            
            result.push_back(temp);
        }
        
        return result;
        
    }
};
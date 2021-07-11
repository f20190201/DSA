class Solution {
public:
    vector<vector<int>> generate(int n) {
        
        vector<vector<int>> result;
        result.push_back({1});
        
        if(n == 1)
            return result;
        
        result.push_back({1 , 1});
            
        if(n == 2)
            return result;
        
        for(int i = 3 ; i <= n ; i++){
            
            vector<int>temp(i);
            temp[0] = 1;
            temp[i - 1] = 1;
            
            for(int j = 1 ; j < (i - 1) ; j++)
                temp[j] = result[result.size() - 1][j] + result[result.size() - 1][j - 1];
            
            result.push_back(temp);
        }
        
        return result;
    }
};